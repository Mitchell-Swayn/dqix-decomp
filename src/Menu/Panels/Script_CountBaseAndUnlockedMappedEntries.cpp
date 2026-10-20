#include <globaldefs.h>
ARM
extern "C" void *GameState_GetSerializedProgressState(void);
extern "C" unsigned short Script_CollectMappedUpperEntryFlagMask(char *p);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E9B00; symbol: func_ov023_021e9b00; size: 0x48.
extern "C" int Script_CountBaseAndUnlockedMappedEntries(void *output) {
    unsigned int mask = Script_CollectMappedUpperEntryFlagMask((char *)GameState_GetSerializedProgressState());
    unsigned int bits = 0xFFFF | (mask << 16);
    int count = 0;
    while (bits != 0) {
        count += bits & 1;
        bits >>= 1;
    }
    Script_WriteIntegerReferenceOutput(output, count);
    return 1;
}
