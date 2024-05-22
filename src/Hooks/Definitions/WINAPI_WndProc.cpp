#include "../Hooks.h"

using namespace Hooks;

LRESULT CALLBACK WINAPI_WndProc::Detour(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return CallWindowProcW(oWndProc, hwnd, uMsg, wParam, lParam);
}

void WINAPI_WndProc::Initialize()
{
	while (!hwGame)
	{
		hwGame = FindWindowW(L"Valve001", nullptr);
		Sleep(100);
	}

	oWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtrW(hwGame, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(Detour)));
}
void WINAPI_WndProc::UnInitialize()
{
	if (oWndProc)
		SetWindowLongPtrW(hwGame, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(oWndProc));
}