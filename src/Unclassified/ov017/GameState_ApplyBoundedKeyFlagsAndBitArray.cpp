#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalValueAt020FB3F0(void);
extern "C" void* ReadGlobalValueAt02108844(void);
extern "C" void func_02017098(void*, unsigned);
extern "C" void* ReadGlobalAt020FDD44(void);
extern "C" void* FindRecordAmongFourByNonnegativeKey(void*, int);
extern "C" void Object_SetBoundedTwelveBitFlag(void*, int);
extern "C" void BitArray_SetIndexedBoolean(void*, unsigned char*, int, int);
// Original: arm9/ov017 @ 0x021B6174; symbol: func_ov017_021b6174; size: 0x70.
extern "C" void GameState_ApplyBoundedKeyFlagsAndBitArray(unsigned key, unsigned value, int bit) {
    unsigned short* first = (unsigned short*)ReadGlobalValueAt020FB3F0();
    void* second = ReadGlobalValueAt02108844();
    if (key == *first) func_02017098(first, value);
    void* record = FindRecordAmongFourByNonnegativeKey(ReadGlobalAt020FDD44(), key);
    if (record != 0) Object_SetBoundedTwelveBitFlag(record, value);
    BitArray_SetIndexedBoolean(second, (unsigned char*)second + 0x8c, bit + 0x79e, 1);
}
