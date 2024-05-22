#include "Hooks.h"

using namespace Hooks;

void CGlobal_Hooks::Initialize()
{
	XASSERT(MH_Initialize() != MH_STATUS::MH_OK);

	ClientModeShared_CreateMove::Initialize();
	IEngineVGui_Paint::Initialize();
	IBaseClientDLL_LevelInitPostEntity::Initialize();
	IBaseClientDLL_LevelShutdown::Initialize();
	IBaseClientDLL_FrameStageNotify::Initialize();
	CL_CheckForPureServerWhitelist::Initialize();
	CTFPlayer_AvoidPlayers::Initialize();
	CPrediction_RunCommand::Initialize();
	ISurface_OnScreenSizeChanged::Initialize();

	XASSERT(MH_EnableHook(MH_ALL_HOOKS) != MH_STATUS::MH_OK);

	WINAPI_WndProc::Initialize();
}

void CGlobal_Hooks::UnInitialize()
{
	WINAPI_WndProc::UnInitialize();

	XASSERT(MH_Uninitialize() != MH_STATUS::MH_OK);
}
