#include <globaldefs.h>
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_ov000_02177ac8(void *, void *);
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(void *, unsigned, void *, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x02177A7C; symbol: func_ov000_02177a7c; size: 0x4C.
extern "C" void OV000_ClearLookupScratchAndRefresh(void *owner) {
    unsigned char *buffer = (unsigned char *)(*(unsigned *)(ReadWordFieldAtOffset1C() + 0x5c));
    memset(buffer, 0, 0x960);
    func_ov000_02177ac8(owner, buffer);
    LoadMatchingReadyRecordAndRefreshOwner((char *)owner + 0x188, 4, buffer, 1, 0);
}
