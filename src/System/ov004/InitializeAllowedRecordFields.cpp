#include <globaldefs.h>
ARM
extern "C" unsigned short ReadSharedRecordSizeForAllowedTypes();
extern "C" void GameState_AppendValueAndSetNodeFlags(void*, unsigned, unsigned);
extern "C" void func_ov023_021f6600(void*, unsigned, unsigned);
// Original: arm9/ov004 @ 0x0215781C; symbol: func_ov004_0215781c; size: 0x58.
extern "C" void InitializeAllowedRecordFields(void* record) {
    unsigned short count = ReadSharedRecordSizeForAllowedTypes();
    unsigned size = 8;
    for (int i = 0; i < 4; ++i) {
        if (i == count) func_ov023_021f6600(record, i + 0x29, size);
        else GameState_AppendValueAndSetNodeFlags(record, i + 0x29, 8);
    }
}
