#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250c00; symbol: data_ov031_02250c00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_GetSpriteGroupPosition(void*, int, unsigned*, unsigned*);
extern "C" int WfcNumberPad_LayoutRow(unsigned, unsigned);
extern "C" int ConfigureEffectSpriteBySignedIndex();
extern "C" int WfcUtility_SetTaskCallback(void*, void*);
extern "C" void InitializeOverlayInputHandlers();
// Original: arm9/ov031 @ 0x02225EA0; symbol: func_ov031_02225ea0; size: 0x74.
extern "C" int UpdatePackedEffectValue(void* object) {
    unsigned high, low;
    void* source = *(void**)WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;
    WfcUtility_GetSpriteGroupPosition(*(void**)((char*)source + 0x40), 0, &high, &low);
    unsigned adjusted = low - 0xc;
    low = adjusted;
    if ((int)adjusted > 0xaa) return WfcNumberPad_LayoutRow(4, adjusted);
    WfcNumberPad_LayoutRow(4, 0xaa);
    ConfigureEffectSpriteBySignedIndex();
    return WfcUtility_SetTaskCallback(object, (void*)InitializeOverlayInputHandlers);
}
