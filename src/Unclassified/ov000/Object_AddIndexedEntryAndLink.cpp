#include <globaldefs.h>
extern "C" void* func_ov000_0215e9b8(void*);
extern "C" void Util_AppendLinkedNodeAndIncrementCount(void*, void*);
// Original: arm9/ov000 @ 0x0215A88C; symbol: func_ov000_0215a88c; size: 0x48.
extern "C" void Object_AddIndexedEntryAndLink(void* self, void* object, unsigned short id) {
    void* entry = func_ov000_0215e9b8(self);
    if (entry == 0) return;
    *(unsigned short*)entry = 0;
    *(unsigned*)((char*)entry + 4) = 0;
    *(unsigned short*)entry = id;
    Util_AppendLinkedNodeAndIncrementCount(object, entry);
    *((unsigned char*)self + 0x8e03) += 1;
}
