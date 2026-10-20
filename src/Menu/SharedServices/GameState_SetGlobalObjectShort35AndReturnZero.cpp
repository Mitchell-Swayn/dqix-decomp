#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" void Bgm_RequestTemporarySequence(int self, unsigned short value);
// Original: arm9/ov004 @ 0x0216DFA0; symbol: func_ov004_0216dfa0; size: 0x1C.
extern "C" int GameState_SetGlobalObjectShort35AndReturnZero(void) {
    Bgm_RequestTemporarySequence((int)Main_UnknownRoleZeroInitializedStorage_Variant2, 0x35);
    return 0;
}
