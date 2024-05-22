#include "../Hooks.h"

DEFINE_HOOK(ISurface_OnScreenSizeChanged, void, __fastcall, FASTCALL_PARAMS, int nOldWidth, int nOldHeight)
{
	Func.Original<FN>()(FASTCALL_ARGS, nOldWidth, nOldHeight);

	H::Draw.UnInitialize();
	H::Draw.Initialize();
}