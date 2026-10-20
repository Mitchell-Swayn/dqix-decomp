#include <globaldefs.h>
ARM
extern "C" void* Combat_FindIndexedMonsterObject(void*);
// Original: arm9/ov024 @ 0x021F51D4; symbol: func_ov024_021f51d4; size: 0x4C.
extern "C" int Grotto_CheckNestedModeAndWriteOutputs(void** object, unsigned short value, unsigned unused, int* outFlag, unsigned short* outValue) {
    void* found = Combat_FindIndexedMonsterObject(*object);
    if (found == 0) return 0;
    int mode = *(int*)((char*)*(void**)((char*)found + 0x138) + 0x58);
    mode = (mode << 2) >> 29;
    if (mode >= 2) return 0;
    *outFlag = 1;
    *outValue = value;
    return 1;
}
