#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cf4; symbol: data_ov031_02290cf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_SetSpriteGroupPosition(void*, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x02235744; symbol: ApplyContextValueAndStoreByte1A; size: 0x3C.
// Uses context halfwords +0x10/+0x12 to call the context updater with the supplied value, then stores that value at context byte +0x1A.
extern "C" void ApplyContextValueAndStoreByte1A(unsigned int value) {
    unsigned char* context = *(unsigned char**)((char*)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage);
    unsigned int second = *(unsigned short*)(context + 0x10);
    unsigned int third = *(unsigned short*)(context + 0x12);
    WfcUtility_SetSpriteGroupPosition(*(void**)context, 0xffffffff, second, value + third);
    (*(unsigned char**)((char*)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage))[0x1a] = (unsigned char)value;
}
