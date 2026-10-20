#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" void Bgm_RequestTemporarySequence(int, unsigned short);
// Original: arm9/ov004 @ 0x0216DFBC; symbol: func_ov004_0216dfbc; size: 0x1C.
extern "C" int TitleMenu_PlayRecoveryFailureMusic(void) {
    Bgm_RequestTemporarySequence((int)&Main_UnknownRoleZeroInitializedStorage_Variant2, 0x3d);
    return 0;
}
