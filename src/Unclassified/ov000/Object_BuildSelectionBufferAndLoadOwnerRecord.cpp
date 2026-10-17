#include <globaldefs.h>
extern "C" void* memset(void*, int, unsigned);
extern "C" void* FindIndexedRecordMatchingCurrentKey(char*);
extern "C" void func_ov000_02179194(void*, void*);
extern "C" void Text_AppendSelectionPageEntries(char*, char*, char*);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x02179128; symbol: func_ov000_02179128; size: 0x6C.
extern "C" void Object_BuildSelectionBufferAndLoadOwnerRecord(void* object) {
    void* entry = FindIndexedRecordMatchingCurrentKey((char*)object);
    func_ov000_02179194(object, entry);
    unsigned char* owner = (unsigned char*)ReadWordFieldAtOffset1C();
    char* buffer = *(char**)(owner + 0x5c);
    memset(buffer, 0, 0x960);
    Text_AppendSelectionPageEntries((char*)object, (char*)entry, buffer);
    LoadMatchingReadyRecordAndRefreshOwner((char*)object + 0x188, 0x10, buffer, 1, 0);
}
