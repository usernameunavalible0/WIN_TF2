#include "../Hooks.h"
#include "../../Features/ESP/ESP.h"

DEFINE_HOOK(IEngineVGui_Paint, void, __fastcall, FASTCALL_PARAMS, PaintMode_t mode)
{
	Func.Original<FN>()(FASTCALL_ARGS, mode);

	if (mode & PaintMode_t::PAINT_UIPANELS)
	{
		H::Draw.UpdateMatrix();

		I::MatSystemSurface->StartDrawing();
		{
			//DO YOUR DRAWING HERE.
			F::ESP.Render();

			H::Draw.String(EFonts::DEBUG, 5, 5, { 204, 204, 204, 255 }, TXT_DEFAULT, "WIN! %s by whydoIhax - unknowncheats.me", IsWin64() ? "x64" : "x86");
		}
		I::MatSystemSurface->FinishDrawing();
	}
}