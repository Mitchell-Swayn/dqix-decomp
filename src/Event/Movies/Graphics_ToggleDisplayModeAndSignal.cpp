#include <globaldefs.h>
ARM
extern "C" void Graphics_SetMainDisplayModeAndSelection(unsigned short,unsigned,int);
// Original data: arm9/ov016 @ 0x219d144; symbol: data_ov016_0219d144.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/dtcm @ 0x27e0000; symbol: data_027e0000.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex c8690c02c8690c02c8690c02946a0c02a46a0c02b46a0c02c46a0c02c8690c02546a0c02646a0c02746a0c02846a0c02c8690c02c8690c02c8690c02c8690c02 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/dtcm.md.
extern "C" char Entry_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov016 @ 0x0218D034; symbol: func_ov016_0218d034; size: 0xA0.
extern "C" void Graphics_ToggleDisplayModeAndSignal() {
if(!MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[12]) {
MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[12]=1;
if(MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[1]==0) {
Graphics_SetMainDisplayModeAndSelection(6,0,0);
*(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x1000;
} else {
Graphics_SetMainDisplayModeAndSelection(2,0,0);
*(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x400;
}
MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[1]^=1;
}
char* flags=Entry_UnknownRoleProcedureReferenceRecords;
flags+=0x3000;
*(unsigned*)(flags+0xff8)|=1;
}
