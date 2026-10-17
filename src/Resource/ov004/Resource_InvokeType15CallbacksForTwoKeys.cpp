#include <globaldefs.h>
extern "C" unsigned char data_ov004_021707d8[];
extern "C" void* FindType15EntryForState(void*, unsigned);
// Original: arm9/ov004 @ 0x0215AF80; symbol: func_ov004_0215af80; size: 0x70.
extern "C" int Resource_InvokeType15CallbacksForTwoKeys(void* self) {
    void* entry = FindType15EntryForState(self, 0x25a);
    if (entry != 0) {
        void* context = *(void**)(data_ov004_021707d8 + 8);
        void** vtable = *(void***)entry;
        ((void (*)(void*, unsigned))(*(void**)((char*)vtable + 0xe0)))(entry, *(unsigned char*)((char*)context + 0x6e));
    }
    entry = FindType15EntryForState(self, 0x2bd);
    if (entry != 0) {
        void* context = *(void**)(data_ov004_021707d8 + 8);
        void** vtable = *(void***)entry;
        ((void (*)(void*, unsigned))(*(void**)((char*)vtable + 0xe0)))(entry, *(unsigned*)((char*)context + 0x78));
    }
    return 0;
}
