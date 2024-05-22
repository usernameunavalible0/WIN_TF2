#pragma once
#include "../DrawManager/DrawManager.h"

class CHelpers_Input
{
public:
	enum EKeyState { NONE, PRESSED, HELD };
	EKeyState m_Keys[256] = {};
	int m_nMouseX = 0, m_nMouseY = 0;
	bool m_bGameFocused = false;

public:
	inline bool IsPressed(short key) { return m_Keys[key] == PRESSED; }
	inline bool IsHeld(short key) { return m_Keys[key] == HELD; }
	inline bool IsDown(short key) { return IsPressed(key) || IsHeld(key); }
	inline int GetMouseX() { return m_nMouseX; }
	inline int GetMouseY() { return m_nMouseY; }
	inline bool IsGameFocused() { return m_bGameFocused; }

public:
	bool IsPrressedAndHeld(short key);
	void Update();
};

namespace H { inline CHelpers_Input Input; }