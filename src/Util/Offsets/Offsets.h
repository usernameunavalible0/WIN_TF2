#pragma once

#include "../Pattern/Pattern.h"

class CUtil_Offsets
{
public:
	void Initialize();

public:
	DWORD_PTR m_dwC_TFPlayer_AvoidPlayers = 0x0;
	DWORD_PTR m_dwC_BaseEntity_SetPredictionRandomSeed = 0x0;
	DWORD_PTR m_dwC_BaseEntity_PhysicsRunThink = 0x0;
	DWORD_PTR m_dwC_BaseEntity_SaveData = 0x0;
	DWORD_PTR m_dwC_BasePlayer_UsingStandardWeaponsInVehicle = 0x0;
	DWORD_PTR m_dwC_BasePlayer_UpdateButtonState = 0x0;
	DWORD_PTR m_dwCL_CheckForPureServerWhitelist = 0x0;
	DWORD_PTR m_dwPredictionPlayer = 0x0;
	DWORD_PTR m_dwStartDrawing = 0x0;
	DWORD_PTR m_dwFinishDrawing = 0x0;
	DWORD_PTR m_dwGlobalVars = 0x0;
};

namespace U { inline CUtil_Offsets Offsets; }