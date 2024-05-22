#include "Offsets.h"

#define GETPATT_INTERNAL(x, mod, patt, off) x = U::Pattern.Find(mod, patt) + off; XASSERT(x == off)

#ifdef _WIN64
#define GETPATT(x, mod, patt64, patt32, off64, off32) GETPATT_INTERNAL(x, mod, patt64, off64)
#else
#define GETPATT(x, mod, patt64, patt32, off64, off32) GETPATT_INTERNAL(x, mod, patt32, off32)
#endif

void CUtil_Offsets::Initialize()
{
	// Structure: Variable Name, Game Module, 64 bit signature, 32 bit signature, 64 bit offset, 32 bit offset
	GETPATT(m_dwC_TFPlayer_AvoidPlayers, "client.dll", "48 89 54 24 ? 55 41 56", "55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 57 8B F9 89 7D ? 83 78 ? ? 0F 84 ? ? ? ? A1", 0x0, 0x0);
	GETPATT(m_dwC_BaseEntity_SetPredictionRandomSeed, "client.dll", "48 85 C9 75 ? C7 05 ? ? ? ? ? ? ? ? C3", "55 8B EC 8B 45 08 85 C0 75 0C", 0x0, 0x0);
	GETPATT(m_dwC_BaseEntity_PhysicsRunThink, "client.dll", "4C 8B DC 49 89 73 ? 57 48 81 EC ? ? ? ? 8B 81", "55 8B EC 53 8B D9 56 57 8B 83 ? ? ? ? C1", 0x0, 0x0);
	GETPATT(m_dwC_BaseEntity_SaveData, "client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 81 EC ? ? ? ? 48 8B F9 4C 8D 81", "55 8B EC 81 EC ? ? ? ? 53 8B D9 57 8B 7D", 0x0, 0x0);
	GETPATT(m_dwC_BasePlayer_UsingStandardWeaponsInVehicle, "client.dll", "48 89 5C 24 ? 57 48 83 EC ? 8B 91 ? ? ? ? 48 8B F9 85 D2 74 ? B8 ? ? ? ? 83 FA ? 74 ? 0F B7 C2 4C 8B 05", "56 57 8B F9 8B 97 ? ? ? ? 85 D2 74 52", 0x0, 0x0);
	GETPATT(m_dwC_BasePlayer_UpdateButtonState, "client.dll", "44 8B 81 ? ? ? ? 89 91", "55 8B EC 8B 55 08 56 8B B1", 0x0, 0x0);
	GETPATT(m_dwPredictionPlayer, "client.dll", "48 89 3D ? ? ? ? 66 0F 6E 87", "89 3D ? ? ? ? F3 0F 2A", 0x0, 0x2);

	GETPATT(m_dwGlobalVars, "engine.dll", "48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B 15", "A1 ? ? ? ? 8B 11 68 ? ? ? ? 50 50 FF 12", 0x0, 0x8);
	GETPATT(m_dwCL_CheckForPureServerWhitelist, "engine.dll", "40 56 48 83 EC ? 83 3D ? ? ? ? ? 48 8B F1 0F 8E", "55 8B EC 83 EC ? 83 3D ? ? ? ? ? 0F 8E", 0x0, 0x0);

	GETPATT(m_dwStartDrawing, "vguimatsurface.dll", "40 53 56 57 48 83 EC ? 48 8B F9 80 3D", "55 8B EC 64 A1 ? ? ? ? 6A ? 68 ? ? ? ? 50 64 89 25 ? ? ? ? 83 EC ? 80 3D ? ? ? ? ? 56", 0x0, 0x0);
	GETPATT(m_dwFinishDrawing, "vguimatsurface.dll", "40 53 48 83 EC ? 33 C9", "55 8B EC 6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 64 89 25 ? ? ? ? 51 56 6A", 0x0, 0x0);
}