#pragma once

#include "../SDK/SDK.h"

//On 64-Bit, all existing calling conventions are changed to the Microsoft x64 calling convention
CREATE_HOOK(ClientModeShared_CreateMove, U::VFunc.Get<void*>(I::ClientMode, 21u), bool, __fastcall, FASTCALL_PARAMS, float flInputSampleTime, CUserCmd* cmd);
CREATE_HOOK(IEngineVGui_Paint, U::VFunc.Get<void*>(I::EngineVGui, 14u), void, __fastcall, FASTCALL_PARAMS, PaintMode_t mode);
CREATE_HOOK(IBaseClientDLL_LevelInitPostEntity, U::VFunc.Get<void*>(I::BaseClientDLL, 6u), void, __fastcall, FASTCALL_PARAMS);
CREATE_HOOK(IBaseClientDLL_LevelShutdown, U::VFunc.Get<void*>(I::BaseClientDLL, 7u), void, __fastcall, FASTCALL_PARAMS);
CREATE_HOOK(IBaseClientDLL_FrameStageNotify, U::VFunc.Get<void*>(I::BaseClientDLL, 35u), void, __fastcall, FASTCALL_PARAMS, ClientFrameStage_t curStage);
#ifdef _WIN64
CREATE_HOOK(CL_CheckForPureServerWhitelist, U::Offsets.m_dwCL_CheckForPureServerWhitelist, void, __cdecl, void* rcx, void* &pFilesToReload);
#else
CREATE_HOOK(CL_CheckForPureServerWhitelist, U::Offsets.m_dwCL_CheckForPureServerWhitelist, void, __cdecl, void* &pFilesToReload);
#endif
CREATE_HOOK(CTFPlayer_AvoidPlayers, U::Offsets.m_dwC_TFPlayer_AvoidPlayers, void, __fastcall, FASTCALL_PARAMS, CUserCmd* pCmd);
CREATE_HOOK(CPrediction_RunCommand, U::VFunc.Get<void*>(I::ClientPrediction, 17u), void, __fastcall, FASTCALL_PARAMS, C_BasePlayer* player, CUserCmd* ucmd, IMoveHelper* moveHelper);
CREATE_HOOK(ISurface_OnScreenSizeChanged, U::VFunc.Get<void*>(I::MatSystemSurface, 111u), void, __fastcall, FASTCALL_PARAMS, int nOldWidth, int nOldHeight);

namespace Hooks
{
	namespace WINAPI_WndProc
	{
		inline WNDPROC oWndProc = nullptr;
		inline HWND hwGame = nullptr;
		LRESULT CALLBACK Detour(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		void Initialize();
		void UnInitialize();
	}
}

class CGlobal_Hooks
{
public:
	void Initialize();
	void UnInitialize();
};

namespace G { inline CGlobal_Hooks Hooks; }