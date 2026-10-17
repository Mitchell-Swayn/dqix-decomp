#include <globaldefs.h>
ARM
extern "C" void func_0204b088(void*, int);
extern "C" void ResetEachIndexedEntryResource(void*);
// Original: arm9/ov000 @ 0x021742C8; symbol: func_ov000_021742c8; size: 0x5C.
extern "C" void ResetStateEntryResources(void* state) {
    unsigned flags = *(unsigned short*)((char*)state + 0x1d72);
    if ((flags & 0x40) == 0) return;
    if (flags & 0x80) {
        func_0204b088((char*)state + 0x8c4, 0);
        return;
    }
    func_0204b088((char*)state + 0x8a4, 0);
    func_0204b088((char*)state + 0x8c4, 0);
    ResetEachIndexedEntryResource((char*)state + 0x188);
}
