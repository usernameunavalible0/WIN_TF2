#include "../Hooks.h"
#include "../../Features/Vars.h"

#ifdef _WIN64
DEFINE_HOOK(CL_CheckForPureServerWhitelist, void, __cdecl, void* rcx, void* &pFilesToReload)
#else
DEFINE_HOOK(CL_CheckForPureServerWhitelist, void, __cdecl, void* &pFilesToReload)
#endif
{
	if (Vars::Misc::PureBypass.Get())
		return;

#ifdef _WIN64
	Func.Original<FN>()(rcx, pFilesToReload);
#else
	Func.Original<FN>()(pFilesToReload);
#endif
}