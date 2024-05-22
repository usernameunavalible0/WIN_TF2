#pragma once

#include "../Hooks/Hooks.h"

class CGlobal_Entry
{
public:
	void Load();
	void UnLoad();
};

namespace G { inline CGlobal_Entry Entry; }