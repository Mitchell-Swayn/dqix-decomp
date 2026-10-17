#include <globaldefs.h>

extern "C" void SerializedLoader_LoadAndInitializeFiveWordOutput(void*, void*, int, int, int);
extern "C" void func_020def98(int, void*, void*, void*, int);

// Original: arm9/main @ 0x020DEF44; symbol: func_020def44; size: 0x54.
extern "C" void BuildTwoTemporaryDescriptorsAndDispatchSingleValue(int a0, int a1, int a2, int a3)
{
    char first[20];
    char second[20];
    SerializedLoader_LoadAndInitializeFiveWordOutput(second, first, a0, a1, a2);
    func_020def98(0, first, second, &a3, 1);
}
