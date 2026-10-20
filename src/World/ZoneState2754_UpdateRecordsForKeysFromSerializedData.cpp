#include <globaldefs.h>

extern "C" void SerializedLoader_LoadAndInitializeFiveWordOutput(void*, void*, int, int, int);
extern "C" void ZoneState2754_CopyRecordsForKeys(int, void*, void*, int, int);

// Original: arm9/main @ 0x020DEEF4; symbol: func_020deef4; size: 0x50.
extern "C" void ZoneState2754_UpdateRecordsForKeysFromSerializedData(int a0, int a1, int a2, int a3, short a4)
{
    char first[20];
    char second[20];
    SerializedLoader_LoadAndInitializeFiveWordOutput(first, second, a0, a1, a2);
    ZoneState2754_CopyRecordsForKeys(0, second, first, a3, a4);
}
