#include <globaldefs.h>
ARM
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*, void*);
extern "C" void func_0204500c(int, int, int, int);
// Original: arm9/ov003 @ 0x0217DD10; symbol: func_ov003_0217dd10; size: 0x50.
extern "C" void Resource_InitializeOwnerRecordState(void* object, int selector) {
    unsigned global = ReadWordFieldAtOffset1C();
    void* record = ResolveIndexedRecordAndReturnSecondWord((char*)object + 0xcc, (void*)(short)selector);
    func_0204500c(global, (int)record, 0, 0xe3);
    *(unsigned char*)(global + 0x19b2) = 1;
    *(unsigned*)(global + 0x99c) = 2;
}
