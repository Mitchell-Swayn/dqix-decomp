#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void Text_FormatCharacterPackedSummary(void *);
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(void *, unsigned int, void *, unsigned int, unsigned char);
// Original: arm9/ov023 @ 0x021E7FE4; symbol: func_ov023_021e7fe4; size: 0x48.
extern "C" void Grotto_ResetObjectBufferAndLoadRecord(void *owner) {
    volatile void **bufferSlot = (volatile void **)((char *)owner + 0x5d8);
    memset((void *)*bufferSlot, 0, 0x960);
    Text_FormatCharacterPackedSummary(owner);
    LoadMatchingReadyRecordAndRefreshOwner((char *)owner + 0x78, 0xb, (void *)*bufferSlot, 1, 0);
}
