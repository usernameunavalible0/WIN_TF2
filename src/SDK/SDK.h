#pragma once

#include "Helpers/Input/Input.h"

namespace I { inline void* ClientMode = nullptr; }

namespace Util
{
	inline Color GetHealthColor(const int nHealth, const int nMaxHealth)
	{
		if (nHealth > nMaxHealth)
			return { 15, 150, 150, 255 };

		const int nHP = U::Math.Max(0, U::Math.Min(nHealth, nMaxHealth));

		const unsigned int nR = static_cast<unsigned int>(U::Math.Min((510 * (nMaxHealth - nHP)) / nMaxHealth, 200));
		const unsigned int nG = static_cast<unsigned int>(U::Math.Min((510 * nHP) / nMaxHealth, 200));

		return { static_cast<byte>(nR), static_cast<byte>(nG), 0, 255 };
	}

	inline Color GetTeamColor(const int nTeam)
	{
		if (nTeam == 2)
			return COLOR_TF_RED;
		else if (nTeam == 3)
			return COLOR_TF_BLUE;
		else
			return COLOR_TF_SPECTATOR;
	}

	inline ETextures GetClassIcon(const int nClass)
	{
		switch (nClass)
		{
		case TF_CLASS_SCOUT: return ETextures::ICON_SCOUT;
		case TF_CLASS_SNIPER: return ETextures::ICON_SNIPER;
		case TF_CLASS_SOLDIER: return ETextures::ICON_SOLDIER;
		case TF_CLASS_DEMOMAN: return ETextures::ICON_DEMO;
		case TF_CLASS_MEDIC: return ETextures::ICON_MEDIC;
		case TF_CLASS_HEAVYWEAPONS: return ETextures::ICON_HEAVY;
		case TF_CLASS_PYRO: return ETextures::ICON_PYRO;
		case TF_CLASS_SPY: return ETextures::ICON_SPY;
		case TF_CLASS_ENGINEER: return ETextures::ICON_ENGI;
		default: break;
		}

		return ETextures::TEXTURE_LAST;
	}
}