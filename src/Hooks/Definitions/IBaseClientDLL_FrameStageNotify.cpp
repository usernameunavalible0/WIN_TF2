#include "../Hooks.h"

DEFINE_HOOK(IBaseClientDLL_FrameStageNotify, void, __fastcall, FASTCALL_PARAMS, ClientFrameStage_t curStage)
{
	if (curStage == ClientFrameStage_t::FRAME_RENDER_START)
	{
		H::Input.Update();
	}

	Func.Original<FN>()(FASTCALL_ARGS, curStage);

	if (curStage == ClientFrameStage_t::FRAME_NET_UPDATE_END)
	{
		g_Globals.m_bIsInGame = I::EngineClient->IsInGame();
		g_Globals.m_bIsGameUIVisible = I::EngineVGui->IsGameUIVisible();

		if (g_Globals.m_bIsInGame)
		{
			g_Globals.m_nMaxClients = I::EngineClient->GetMaxClients();
			g_Globals.m_nMaxEntities = I::ClientEntityList->GetMaxEntities();
		}
	}
}