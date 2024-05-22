#include "Entry.h"

void CGlobal_Entry::Load()
{
	//while (!GetModuleHandleW(L"mss32.dll")

	U::Offsets.Initialize();

	//Interfaces
	{
		I::BaseClientDLL = U::Interface.Get<IBaseClientDLL*>("client.dll", "VClient017");
		I::ClientEntityList = U::Interface.Get<IClientEntityList*>("client.dll", "VClientEntityList003");
		I::GameMovement = U::Interface.Get<IGameMovement*>("client.dll", "GameMovement001");
		I::ClientPrediction = U::Interface.Get<CPrediction*>("client.dll", "VClientPrediction001");

		I::EngineVGui = U::Interface.Get<IEngineVGui*>("engine.dll", "VEngineVGui002");
		I::ModelInfoClient = U::Interface.Get<IVModelInfoClient*>("engine.dll", "VModelInfoClient006");
		I::GameEventManager = U::Interface.Get<IGameEventManager2*>("engine.dll", "GAMEEVENTSMANAGER002");
		I::EngineClient = U::Interface.Get<IVEngineClient*>("engine.dll", "VEngineClient014");
		I::RenderView = U::Interface.Get<IVRenderView*>("engine.dll", "VEngineRenderView014");

		I::MatSystemSurface = U::Interface.Get<IMatSystemSurface*>("vguimatsurface.dll", "VGUI_Surface030");

		//Other shenanigans
		{
			const DWORD_PTR dwpFunc = U::VFunc.Get<DWORD_PTR>(I::BaseClientDLL, 10u);
			XASSERT(dwpFunc == NULL);

#ifdef _WIN64
			//64 bit relative addresses: (address of ptr in instruction) + instruction + (size of instruction)
			I::ClientMode = *reinterpret_cast<void**>(*reinterpret_cast<DWORD*>(dwpFunc + 0x03) + dwpFunc + 0x07);
			I::GlobalVarsBase = reinterpret_cast<CGlobalVarsBase*>(*reinterpret_cast<DWORD*>(U::Offsets.m_dwGlobalVars + 0xA) + U::Offsets.m_dwGlobalVars + 0xE);
#else
			I::ClientMode = **reinterpret_cast<void***>(dwpFunc + 0x05);
			I::GlobalVarsBase = *reinterpret_cast<CGlobalVarsBase**>(U::Offsets.m_dwGlobalVars);
#endif
			XASSERT(I::ClientMode == nullptr);
			XASSERT(I::GlobalVarsBase == nullptr);
		}
	}

	H::Draw.Initialize();

	if (I::EngineClient->IsInGame())
		g_Globals.m_nLocalIndex = I::EngineClient->GetLocalPlayer();

	G::Hooks.Initialize();
}

void CGlobal_Entry::UnLoad()
{
	G::Hooks.UnInitialize();

	Sleep(100);

	H::Draw.UnInitialize();
	
	Sleep(100);
}
