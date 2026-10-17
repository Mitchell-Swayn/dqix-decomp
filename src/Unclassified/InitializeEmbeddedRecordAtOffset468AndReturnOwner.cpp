#include <globaldefs.h>
extern "C" void func_0200f3a4(void);
extern "C" void AllocatorUnion_FreeStoredPointer(int);

// Original: arm9/main @ 0x02012224; symbol: func_02012224; size: 0x20.
extern "C" int InitializeEmbeddedRecordAtOffset468AndReturnOwner(int object) {
    func_0200f3a4();
    AllocatorUnion_FreeStoredPointer(object + 0x468);
    return object;
}
