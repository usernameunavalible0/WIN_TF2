#include "../Hooks.h"
#include "../../Features/EnginePrediction/EnginePrediction.h"
#include "../../Features/Misc/Misc.h"

DEFINE_HOOK(ClientModeShared_CreateMove, bool, __fastcall, FASTCALL_PARAMS, float flInputSampleTime, CUserCmd* cmd)
{
	if (!cmd || !cmd->command_number)
		return Func.Original<FN>()(FASTCALL_ARGS, flInputSampleTime, cmd);

	if (Func.Original<FN>()(FASTCALL_ARGS, flInputSampleTime, cmd))
		I::EngineClient->SetViewAngles(cmd->viewangles);

	C_TFPlayer* pLocal = Util::TFPlayerByIndex(g_Globals.m_nLocalIndex);

	if (pLocal && pLocal->IsAlive())
	{
		F::Misc.Run(pLocal, cmd);

		C_TFWeaponBase* pWeapon = pLocal->GetActiveTFWeapon();

		if (pWeapon)
		{
			F::EnginePrediction.Start(pLocal, cmd);
			{
				// Run your Aimbot, Triggerbot, etc...
			}
			F::EnginePrediction.Finish(pLocal);
		}
	}

	return false;
}