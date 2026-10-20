#include <globaldefs.h>
ARM
extern "C" bool Bgm_IsTemporarySequencePendingOrPlaying(char *p);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov001 @ 0x0216376C; symbol: func_ov001_0216376c; size: 0x3C.
extern "C" unsigned int Bgm_ScriptReadTemporarySequenceActive(void *output) {
    if (Bgm_IsTemporarySequencePendingOrPlaying(Main_UnknownRoleZeroInitializedStorage_Variant2)) {
        Script_WriteIntegerReferenceOutput(output, 1);
    } else {
        Script_WriteIntegerReferenceOutput(output, 0);
    }
    return 1;
}
