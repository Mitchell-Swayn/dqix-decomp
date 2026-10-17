#include <globaldefs.h>
ARM
extern "C" void LoadToMainBG0CharacterData(const void* data, unsigned int offset, unsigned int length);
extern "C" void LoadToSubBG0CharacterData(const void* data, unsigned int offset, unsigned int length);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" char *data_ov031_02290d38;
// Original: arm9/ov031 @ 0x0223C6D8; symbol: func_ov031_0223c6d8; size: 0x88.
extern "C" void Graphics_UploadDirtyBgCharacterData(void *unused, unsigned char *dirty) {
    if (!*dirty) return;
    if (dirty == (unsigned char*)(data_ov031_02290d38 + 0x67c)) {
        _Z25CleanInvalidateCacheRangePKvj(*(void**)(data_ov031_02290d38 + 0x638), 0x6000);
        LoadToMainBG0CharacterData(*(void**)(data_ov031_02290d38 + 0x638), 0, 0x6000);
    } else {
        _Z25CleanInvalidateCacheRangePKvj(*(void**)(data_ov031_02290d38 + 0x668), 0x3000);
        LoadToSubBG0CharacterData(*(void**)(data_ov031_02290d38 + 0x668), 0x3000, 0x3000);
    }
    *dirty = 0;
}
