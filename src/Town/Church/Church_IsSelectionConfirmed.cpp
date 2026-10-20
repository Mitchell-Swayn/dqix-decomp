#include <globaldefs.h>
ARM
// Returns whether the selected-record predicate at object+0xf4 or either new-halfword mask (1 or 0x400) is true. Evaluates all three calls; exact output differs only in operand order for the final commutative OR after multiple boolean/bitwise variants.
// Original: arm9/ov003 @ 0x0215B328; symbol: TestSelectedRecordReadinessOrNewHalfwordMasks; size: 0x48.
extern "C" int TestSelectedRecordReadyAndByteFlagBitOne(char*, int);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*, unsigned int);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
extern "C" int Church_IsSelectionConfirmed(char* p) {
    int ready = TestSelectedRecordReadyAndByteFlagBitOne(p + 0xf4, 0x14);
    int first = Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 1);
    int second = Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x400);
    return ((first | second) | ready) != 0;
}
