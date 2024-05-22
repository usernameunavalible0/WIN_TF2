#include "../Hooks.h"

DEFINE_HOOK(IBaseClientDLL_LevelInitPostEntity, void, __fastcall, FASTCALL_PARAMS)
{
	Func.Original<FN>()(FASTCALL_ARGS);

	g_Globals.m_nLocalIndex = I::EngineClient->GetLocalPlayer();
}