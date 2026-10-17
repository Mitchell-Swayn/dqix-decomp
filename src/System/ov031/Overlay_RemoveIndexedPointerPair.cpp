#include <globaldefs.h>
extern "C" unsigned char data_ov031_02290d9c[];
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void**);
extern "C" void UnlinkPointerPair(void*);
extern "C" void func_ov031_0223bf48(void*, void*);
// Original: arm9/ov031 @ 0x0223E2EC; symbol: func_ov031_0223e2ec; size: 0x44.
extern "C" void Overlay_RemoveIndexedPointerPair(unsigned index, void* pair) {
    if (*((unsigned char*)pair + 0x11) != 0) FreeSharedAllocationAndClearFlagWithInterruptMask((void**)((char*)pair + 0xc));
    UnlinkPointerPair(pair);
    func_ov031_0223bf48(*(void**)((char*)*(void**)data_ov031_02290d9c + index * 0x40), pair);
}
