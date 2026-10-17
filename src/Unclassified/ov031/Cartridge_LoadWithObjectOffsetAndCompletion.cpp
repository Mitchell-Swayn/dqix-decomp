#include <globaldefs.h>
ARM
extern "C" int _Z29LoadDataFromCartridgeToMemoryjjPvjPFvP11NitroHandleES1_i(unsigned, unsigned, void*, unsigned, void (*)(void*), void*, int);
extern "C" void Network_CompleteTaskWithZero(void*);
// Original: arm9/ov031 @ 0x0223B5C4; symbol: func_ov031_0223b5c4; size: 0x40.
extern "C" int Cartridge_LoadWithObjectOffsetAndCompletion(void* self, void* destination, unsigned offset, unsigned length) {
    _Z29LoadDataFromCartridgeToMemoryjjPvjPFvP11NitroHandleES1_i((unsigned)-1, offset + *(unsigned*)((char*)self + 0x28), destination, length, Network_CompleteTaskWithZero, self, 1);
    return 6;
}
