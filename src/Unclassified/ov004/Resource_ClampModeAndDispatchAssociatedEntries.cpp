#include <globaldefs.h>
ARM
extern "C" unsigned data_ov004_021707d8;
extern "C" void* FindType15EntryForState(void*, unsigned);
extern "C" void* Unclassified_FindTypeSixObject(void*, unsigned);
extern "C" void func_ov023_021f809c(void*, void*);
// Original: arm9/ov004 @ 0x0215C684; symbol: func_ov004_0215c684; size: 0x78.
extern "C" int Resource_ClampModeAndDispatchAssociatedEntries(void* self) {
    if (*(unsigned char*)(*(unsigned char**)((char*)&data_ov004_021707d8 + 8) + 0x6e) > 1) {
        *(unsigned char*)(*(unsigned char**)((char*)&data_ov004_021707d8 + 8) + 0x6e) = 1;
        void* entry = FindType15EntryForState(self, 0x25a);
        if (entry != 0) {
            void (*callback)(void*, unsigned) = *(void (**)(void*, unsigned))(*(char**)entry + 0xe0);
            callback(entry, *(unsigned char*)(*(unsigned char**)((char*)&data_ov004_021707d8 + 8) + 0x6e));
        }
        void* target = Unclassified_FindTypeSixObject(self, 0x19);
        if (target != 0) func_ov023_021f809c(target, self);
    }
    return 0;
}
