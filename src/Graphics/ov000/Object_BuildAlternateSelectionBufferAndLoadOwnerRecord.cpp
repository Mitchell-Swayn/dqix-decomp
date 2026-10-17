#include <globaldefs.h>
extern "C" void* memset(void*, int, unsigned);
extern "C" void* FindIndexedRecordMatchingCurrentKey(char*);
extern "C" void func_ov000_02178d28(void*, void*);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void func_ov000_02178f28(void*, void*, void*);
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x02178CBC; symbol: func_ov000_02178cbc; size: 0x6C.
extern "C" void Object_BuildAlternateSelectionBufferAndLoadOwnerRecord(void* object) {
    void* entry = FindIndexedRecordMatchingCurrentKey((char*)object);
    func_ov000_02178d28(object, entry);
    unsigned char* owner = (unsigned char*)ReadWordFieldAtOffset1C();
    char* buffer = *(char**)(owner + 0x5c);
    memset(buffer, 0, 0x960);
    func_ov000_02178f28(object, entry, buffer);
    LoadMatchingReadyRecordAndRefreshOwner((char*)object + 0x188, 0xf, buffer, 1, 0);
}
