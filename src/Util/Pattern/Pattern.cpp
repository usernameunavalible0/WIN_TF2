#include "Pattern.h"

#define INRANGE(x,a,b)	(x >= a && x <= b)
#define GetBits(x)		(INRANGE((x & (~0x20)),'A','F') ? ((x & (~0x20)) - 'A' + 0xA) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define GetBytes(x)		(GetBits(x[0]) << 4 | GetBits(x[1]))

DWORD_PTR CUtil_Pattern::Find(const char* const szModule, const char* const szPattern)
{
    const DWORD_PTR dwMod = reinterpret_cast<DWORD_PTR>(GetModuleHandleA(szModule));

    if (!dwMod)
        return 0x0;

    const PIMAGE_NT_HEADERS pNTH = reinterpret_cast<PIMAGE_NT_HEADERS>(dwMod + reinterpret_cast<PIMAGE_DOS_HEADER>(dwMod)->e_lfanew);

    if (!pNTH)
        return 0x0;

    return FindPattern(dwMod + pNTH->OptionalHeader.BaseOfCode, dwMod + pNTH->OptionalHeader.SizeOfCode, szPattern);
}

DWORD_PTR CUtil_Pattern::FindPattern(const DWORD_PTR dwAddress, const DWORD_PTR dwLen, const char* const szPattern)
{
    const char* szPatt = szPattern;
    DWORD_PTR dwFirstMatch = 0x0;

    for (DWORD_PTR dwCur = dwAddress; dwCur < dwLen; dwCur++)
    {
        if (!szPatt)
            return dwFirstMatch;

        const BYTE pCurByte = *(BYTE*)dwCur;
        const BYTE pBytePatt = *(BYTE*)szPatt;

        if (pBytePatt == '\?' || pCurByte == GetBytes(szPatt))
        {
            if (!dwFirstMatch)
                dwFirstMatch = dwCur;

            if (!szPatt[2])
                return dwFirstMatch;

            szPatt += (pBytePatt == '\?\?' || pBytePatt != '\?') ? 3 : 2;
        }
        else
        {
            szPatt = szPattern;
            dwFirstMatch = 0x0;
        }
    }

    return 0x0;
}