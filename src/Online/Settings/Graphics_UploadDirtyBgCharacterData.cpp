#include <globaldefs.h>
ARM
extern "C" void LoadToMainBG0CharacterData(const void* data, unsigned int offset, unsigned int length);
extern "C" void LoadToSubBG0CharacterData(const void* data, unsigned int offset, unsigned int length);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
// Original data: arm9/ov031 @ 0x2290d38; symbol: data_ov031_02290d38.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223C6D8; symbol: func_ov031_0223c6d8; size: 0x88.
extern "C" void Graphics_UploadDirtyBgCharacterData(void* unused,void* context) {
    unsigned char* dirty=(unsigned char*)context;
    if (!*dirty) return;
    if (dirty == (unsigned char*)(WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage + 0x67c)) {
        _Z25CleanInvalidateCacheRangePKvj(*(void**)(WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage + 0x638), 0x6000);
        LoadToMainBG0CharacterData(*(void**)(WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage + 0x638), 0, 0x6000);
    } else {
        _Z25CleanInvalidateCacheRangePKvj(*(void**)(WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage + 0x668), 0x3000);
        LoadToSubBG0CharacterData(*(void**)(WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage + 0x668), 0x3000, 0x3000);
    }
    *dirty = 0;
}
