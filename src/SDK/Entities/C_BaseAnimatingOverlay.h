#pragma once
#include "C_BaseAnimating.h"

class C_BaseAnimatingOverlay : public C_BaseAnimating
{
public:
	virtual ~C_BaseAnimatingOverlay() = 0;

public:
	NETVAR(m_flPrevCycle, float, "CBaseAnimatingOverlay", "m_flPrevCycle");
	NETVAR(m_flWeight, float, "CBaseAnimatingOverlay", "m_flWeight");
	NETVAR(m_nOrder, int, "CBaseAnimatingOverlay", "m_nOrder");
};