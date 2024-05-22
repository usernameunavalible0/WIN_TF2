#include "../Hooks.h"

DEFINE_HOOK(CPrediction_RunCommand, void, __fastcall, FASTCALL_PARAMS, C_BasePlayer* player, CUserCmd* ucmd, IMoveHelper* moveHelper)
{
	if (!I::MoveHelper && moveHelper)
		I::MoveHelper = moveHelper;

	Func.Original<FN>()(FASTCALL_ARGS, player, ucmd, moveHelper);
}