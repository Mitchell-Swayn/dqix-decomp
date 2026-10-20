#include <globaldefs.h>
ARM
extern "C" void AccessPoint_DecodeShopSsidPayload(void*, void*);
extern "C" int RuntimeMemory_CompareByteRanges(const void*, const void*, unsigned);
extern "C" unsigned AccessPoint_CopyDecodedShopIdentifier_TextNDWCSHAP;
// Original: arm9/ov031 @ 0x02215718; symbol: func_ov031_02215718; size: 0x38.
extern "C" int AccessPoint_HasDecodedShopSsidSignature(void* self) {
    unsigned char buffer[0x18];
    AccessPoint_DecodeShopSsidPayload(self, buffer);
    return RuntimeMemory_CompareByteRanges(buffer, &AccessPoint_CopyDecodedShopIdentifier_TextNDWCSHAP, 8) == 0;
}
