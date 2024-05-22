#include "../Hooks.h"
#include "../../Features/Vars.h"

DEFINE_HOOK(CTFPlayer_AvoidPlayers, void, __fastcall, FASTCALL_PARAMS, CUserCmd* pCmd)
{
	if (Vars::Misc::AvoidPushaway.Get())
		return;

	Func.Original<FN>()(FASTCALL_ARGS, pCmd);
}