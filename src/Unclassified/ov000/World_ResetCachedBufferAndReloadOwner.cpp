#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void *ReadWordFieldAtOffset1C(void);
extern "C" void func_ov000_0217737c(void *, void *);
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(void *, unsigned int, void *, unsigned int, unsigned char);
// Original: arm9/ov000 @ 0x02177330; symbol: func_ov000_02177330; size: 0x4C.
extern "C" void World_ResetCachedBufferAndReloadOwner(void *owner) {
    void *buffer = *(void **)((char *)ReadWordFieldAtOffset1C() + 0x5c);
    memset(buffer, 0, 0x960);
    func_ov000_0217737c(owner, buffer);
    LoadMatchingReadyRecordAndRefreshOwner((char *)owner + 0x188, 1, buffer, 1, 0);
}
