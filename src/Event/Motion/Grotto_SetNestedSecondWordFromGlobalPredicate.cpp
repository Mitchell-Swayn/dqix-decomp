#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
extern "C" int Grotto_AreNestedEntryFieldsZero(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x0215D168; symbol: func_ov001_0215d168; size: 0x34.
extern "C" int Grotto_SetNestedSecondWordFromGlobalPredicate(void *arg) {
    void *object = *(void **)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x24);
    int value = Grotto_AreNestedEntryFieldsZero(object) == 0;
    Script_WriteIntegerReferenceOutput(arg, value);
    return 1;
}
