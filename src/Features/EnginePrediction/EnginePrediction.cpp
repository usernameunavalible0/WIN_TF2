#include "EnginePrediction.h"

void CFeatures_EnginePrediction::Start(C_TFPlayer* pLocal, CUserCmd* cmd)
{
	if (!I::MoveHelper)
		return;

	//Used to save & restore original network data
	//Disabled due to weird bugs in collision and weapons
	//pLocal->SaveData("win_pred_data", 1337, 0);

	memset(&m_MoveData, 0, sizeof(CMoveData));

	cmd->random_seed = MD5_PseudoRandom(cmd->command_number) & INT_MAX;

	//StartCommand
	{
		pLocal->m_pCurrentCommand() = cmd;
		C_BaseEntity::SetPredictionRandomSeed(cmd);
		C_BaseEntity::SetPredictionPlayer(pLocal);
	}

	m_fOldCurrentTime = I::GlobalVarsBase->curtime;
	m_fOldFrameTime = I::GlobalVarsBase->frametime;
	m_nOldTickCount = I::GlobalVarsBase->tickcount;

	const int nOldTickBase = pLocal->m_nTickBase();
	const bool bOldIsFirstPrediction = I::ClientPrediction->m_bFirstTimePredicted;
	const bool bOldInPrediction = I::ClientPrediction->m_bInPrediction;

	const int nServerTicks = GetTickbase(pLocal, cmd);

	I::GlobalVarsBase->curtime = TICKS_TO_TIME(nServerTicks);
	I::GlobalVarsBase->frametime = (I::ClientPrediction->m_bEnginePaused ? 0.0f : TICK_INTERVAL);
	I::GlobalVarsBase->tickcount = nServerTicks;

	I::ClientPrediction->m_bFirstTimePredicted = false;
	I::ClientPrediction->m_bInPrediction = true;

	I::GameMovement->StartTrackPredictionErrors(pLocal);

	if (cmd->weaponselect != 0)
	{
		C_BaseCombatWeapon* pWeapon = dynamic_cast<C_BaseCombatWeapon*>(Util::EntityByIndex(cmd->weaponselect));

		if (pWeapon)
			pLocal->SelectItem(pWeapon->GetName(), cmd->weaponsubtype);
	}

	if (cmd->impulse)
	{
		if (!pLocal->GetClientVehicle() || pLocal->UsingStandardWeaponsInVehicle())
			pLocal->m_nImpulse() = cmd->impulse;
	}

	pLocal->UpdateButtonState(cmd->buttons);

	//C_BasePlayer::SetLocalViewAngles just calls the prediction one
	I::ClientPrediction->SetLocalViewAngles(cmd->viewangles);

	//RunPreThink
	{
		if (pLocal->PhysicsRunThink())
			pLocal->PreThink();
	}

	//RunThink
	{
		const int thinktick = pLocal->m_nNextThinkTick();

		if (thinktick > 0 && thinktick < nServerTicks)
		{
			pLocal->m_nNextThinkTick() = TICK_NEVER_THINK;
			pLocal->Think();
		}
	}

	I::ClientPrediction->SetupMove(pLocal, cmd, I::MoveHelper, &m_MoveData);
	I::GameMovement->ProcessMovement(pLocal, &m_MoveData);
	I::ClientPrediction->FinishMove(pLocal, cmd, &m_MoveData);

	//We don't run PostThink for reasons I can't remember
	//pLocal->PostThink();

	pLocal->m_nTickBase() = nOldTickBase;

	I::ClientPrediction->m_bInPrediction = bOldInPrediction;
	I::ClientPrediction->m_bFirstTimePredicted = bOldIsFirstPrediction;
}

void CFeatures_EnginePrediction::Finish(C_TFPlayer* pLocal)
{
	if (!I::MoveHelper)
		return;

	I::GameMovement->FinishTrackPredictionErrors(pLocal);

	//FinishCommand
	{
		pLocal->m_pCurrentCommand() = NULL;
		C_BaseEntity::SetPredictionRandomSeed(NULL);
		C_BaseEntity::SetPredictionPlayer(NULL);
	}
	
	I::GlobalVarsBase->curtime = m_fOldCurrentTime;
	I::GlobalVarsBase->frametime = m_fOldFrameTime;
	I::GlobalVarsBase->tickcount = m_nOldTickCount;

	//pLocal->RestoreData("win_pred_data", 1337, 0);

	//And dont increase tickbase because we ain't him
	//if (I::GlobalVars->frametime > 0) { pLocal->m_nTickBase()++ }
}

int CFeatures_EnginePrediction::GetTickbase(C_TFPlayer* pLocal, CUserCmd* cmd)
{
	static int s_nTick = 0;
	static CUserCmd* s_pLastCmd = nullptr;

	if (cmd)
	{
		if (!s_pLastCmd || s_pLastCmd->hasbeenpredicted)
			s_nTick = pLocal->m_nTickBase();
		else
			s_nTick++;

		s_pLastCmd = cmd;
	}

	return s_nTick;
}