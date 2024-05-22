#pragma once

#include "Hash/Hash.h"

#include <algorithm>
#include <string>
#include <vector>
#include <map>

namespace Util
{
	static std::wstring ConvertUtf8ToWide(const std::string& str)
	{
		int cnt = MultiByteToWideChar(CP_UTF8, 0, str.data(), static_cast<int>(str.length()), NULL, 0);

		std::wstring s(cnt, 0);
		MultiByteToWideChar(CP_UTF8, 0, str.data(), static_cast<int>(str.length()), &s[0], cnt);

		return s;
	}

	template<typename F, typename ... T>
	inline bool CompareGroup(F&& first, T&& ... t)
	{
		return ((first == t) || ...);
	}
}

#ifdef _WIN64
#define IsWin64() true
#define FASTCALL_PARAMS void* rcx
#define FASTCALL_ARGS rcx
#else
#define IsWin64() false
#define FASTCALL_PARAMS void* ecx, void* edx
#define FASTCALL_ARGS ecx, edx
#endif

#define FAILED_TO_HOOK false
#define FAILED_TO_INITIALIZE false

#define CREATE_HOOK(name, address, type, callconvo, ...) namespace Hooks \
{ \
	namespace name \
	{ \
		inline Hook::C_Function Func; \
		using FN = type(callconvo*)(__VA_ARGS__); \
		type callconvo Detour(__VA_ARGS__); \
		inline void Initialize() \
		{ \
			XASSERT(Func.Initialize(reinterpret_cast<void*>(address), &Detour) == FAILED_TO_HOOK); \
		} \
	}\
}

#define DEFINE_HOOK(name, type, callconvo, ...) type callconvo Hooks::name::Detour(__VA_ARGS__)