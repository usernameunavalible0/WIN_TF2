#pragma once

#include "../Math/Math.h"

class CUtil_Pattern
{
public:
	DWORD_PTR Find(const char* const szModule, const char* const szPattern);

private:
	DWORD_PTR FindPattern(const DWORD_PTR dwAddress, const DWORD_PTR dwLen, const char* const szPattern);
};

namespace U { inline CUtil_Pattern Pattern; }