#include <globaldefs.h>
ARM
extern "C" int TestSelectedRecordReadyAndByteFlagBitOne(char *, int);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short *, unsigned int);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov003 @ 0x0216950C; symbol: func_ov003_0216950c; size: 0x48.
extern "C" bool System_TestCombinedReadyFlags(void *object) {
    int ready = TestSelectedRecordReadyAndByteFlagBitOne((char *)object + 0xE4, 0x14);
    int first = Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 1);
    int second = Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x400);
    return (first | second) | ready;
}
