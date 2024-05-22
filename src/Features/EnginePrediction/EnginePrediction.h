#pragma once
#include "../../SDK/SDK.h"

class CFeatures_EnginePrediction
{
public:
	void Start(C_TFPlayer* pLocal, CUserCmd* cmd);
	void Finish(C_TFPlayer* pLocal);

private:
	int GetTickbase(C_TFPlayer* pLocal, CUserCmd* cmd);

private:
	CMoveData m_MoveData = { };
	float m_fOldCurrentTime = 0.0f;
	float m_fOldFrameTime = 0.0f;
	int m_nOldTickCount = 0;
};

namespace F { inline CFeatures_EnginePrediction EnginePrediction; }