#pragma once

#include "../../Entities/C_TFPlayer.h"

#define TXT_DEFAULT		(1 << 0)
#define TXT_LEFT		(1 << 1)
#define TXT_TOP			(1 << 2)
#define TXT_CENTERX		(1 << 3)
#define TXT_CENTERY		(1 << 4)
#define TXT_CENTERXY	TXT_CENTERX | TXT_CENTERY

#define TEX_DEFAULT		(1 << 0)
#define TEX_LEFT		(1 << 1)
#define TEX_TOP			(1 << 2)
#define TEX_CENTERX		(1 << 3)
#define TEX_CENTERY		(1 << 4)
#define TEX_CENTERXY	TEX_CENTERX | TEX_CENTERY

enum class EFonts {
	DEBUG,
	ESP,
	ESP_NAME,
	ESP_WEAPON,
	PICKUPS,
	MENU_TAHOMA,
	MENU_CONSOLAS,
	MENU_VERDANA,
	MENU_ARIAL,
	MENU_TAB,
	FONT_LAST
};

enum class ETextures {
	ICON_DEMO,
	ICON_ENGI,
	ICON_HEAVY,
	ICON_MEDIC,
	ICON_PYRO,
	ICON_SCOUT,
	ICON_SNIPER,
	ICON_SOLDIER,
	ICON_SPY,
	TEXTURE_LAST
};

class CHelpers_DrawManager
{
private:
	class CFont {
	public:
		const char* m_szName;
		int m_nTall;
		int m_nWeight;
		int m_nFlags;
		HFont m_hFont;
	};

public:
	void Initialize();
	void UnInitialize();
	void UpdateMatrix();

public:
	bool WorldPosToScreenPos(const Vector vWorld, Rect_t& vScreen);
	bool WorldPosToScreenPos(const Vector vWorld, Vector2D& vScreen);

	void String(const EFonts& font, int x, int y, const Color& clr, const short align, const char* const str, ...);
	void String(const EFonts& font, int x, int y, const Color& clr, const short align, const wchar_t* const str, ...);

	void Texture(const ETextures& tex, int x, int y, const int w, const int h, const short align);

	void Line(const int x, const int y, const int x1, const int y1, const Color& clr);
	void Rect(const int x, const int y, const int w, const int h, const Color& clr);
	void OutlinedRect(const int x, const int y, const int w, const int h, const Color& clr);
	void GradientRect(const int x, const int y, const int x1, const int y1, const Color& clrTop, const Color& clrBottom, const bool bHorizontal);
	void OutlinedCircle(const int x, const int y, const int r, const int s, const Color clr);
	void Circle(const int x, const int y, const int r, const int s, const Color clr);
	void Triangle(Vector2D* v, const Color clr);

public:
	int GetFontHeight(const EFonts& font) const;

private:
	std::map<EFonts, CFont> m_Fonts = { };
	std::map<ETextures, int> m_Textures = { };

	VMatrix m_WorldToProjection = { };

public:
	int m_nScreenW = 0;
	int m_nScreenH = 0;
};

namespace H { inline CHelpers_DrawManager Draw; }