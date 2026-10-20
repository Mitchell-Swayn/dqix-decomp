#include <globaldefs.h>
ARM
extern "C" int TestSelectedRecordReadyAndByteFlagBitOne(char *p, int ignored);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short *p, unsigned int mask);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov003 @ 0x0215DCB8; symbol: func_ov003_0215dcb8; size: 0x48.
extern "C" int Inn_IsStayChoiceConfirmed(unsigned char *object) {
    int ready = TestSelectedRecordReadyAndByteFlagBitOne((char *)(object + 0x98), 0x14);
    int first = Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 1);
    int second = Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x400);
    return (first | second | ready) != 0;
}
