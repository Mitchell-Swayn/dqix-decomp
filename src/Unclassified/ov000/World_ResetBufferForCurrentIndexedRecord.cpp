#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void *FindIndexedRecordMatchingCurrentKey(char *);
extern "C" void func_ov000_021781f8(void *, void *);
extern "C" void *ReadWordFieldAtOffset1C(void);
extern "C" void func_ov000_0217831c(void *, void *);
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(void *, unsigned int, void *, unsigned int, unsigned char);
// Original: arm9/ov000 @ 0x0217819C; symbol: func_ov000_0217819c; size: 0x5C.
extern "C" void World_ResetBufferForCurrentIndexedRecord(void *owner) {
    void *record = FindIndexedRecordMatchingCurrentKey((char *)owner);
    func_ov000_021781f8(owner, record);
    void *buffer = *(void **)((char *)ReadWordFieldAtOffset1C() + 0x5c);
    memset(buffer, 0, 0x960);
    func_ov000_0217831c(owner, buffer);
    LoadMatchingReadyRecordAndRefreshOwner((char *)owner + 0x188, 7, buffer, 1, 0);
}
