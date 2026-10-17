#include <globaldefs.h>
extern "C" unsigned char data_ov004_021707d8[];
extern "C" void* FindType15EntryForState(void*, unsigned);
extern "C" void* Unclassified_FindTypeSixObject(void*, unsigned);
extern "C" void func_ov023_021f809c(void*, void*);
// Original: arm9/ov004 @ 0x0215C6FC; symbol: func_ov004_0215c6fc; size: 0x78.
extern "C" int Resource_AdvanceContextByteAndDispatchEntries(void* object) {
    unsigned char* context = *(unsigned char**)(data_ov004_021707d8 + 8);
    if (context[0x6e] < context[0x6f]) {
        context[0x6e] = context[0x6f];
        void* entry = FindType15EntryForState(object, 0x25a);
        if (entry) {
            ((void (*)(void*, unsigned))(*(void**)((char*)*(void**)entry + 0xe0)))(entry, *(unsigned char*)(*(unsigned char**)(data_ov004_021707d8 + 8) + 0x6e));
        }
        entry = Unclassified_FindTypeSixObject(object, 0x19);
        if (entry) func_ov023_021f809c(entry, object);
    }
    return 0;
}
