#include <globaldefs.h>
extern "C" void* FindIndexedRecordMatchingCurrentKey(char*);
extern "C" void* func_ov000_0217964c(void*, void*);
extern "C" unsigned int ReadWordFieldAtOffset1C(void*);
extern "C" void* memset(void*, int, unsigned);
extern "C" void Graphics_FormatPagedRecordNamesWithStyle(void*, void*, void*);
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x021795E0; symbol: func_ov000_021795e0; size: 0x6C.
extern "C" ARM void Ov000_BuildIndexedDescription(void* owner) {
    void* entry = FindIndexedRecordMatchingCurrentKey((char*)owner);
    void* context = func_ov000_0217964c(owner, entry);
    char* buffer = *(char**)(ReadWordFieldAtOffset1C(context) + 0x5c);
    memset(buffer, 0, 0x960);
    Graphics_FormatPagedRecordNamesWithStyle(owner, entry, buffer);
    LoadMatchingReadyRecordAndRefreshOwner((char*)owner + 0x188, 0x11, buffer, 1, 0);
}
