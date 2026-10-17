#include <globaldefs.h>
ARM
extern "C" unsigned char data_02111304[];
extern "C" void Memory_ReserveBufferedCapacity(unsigned size, void* state);
extern "C" void ConsumeBufferBytesAndNotify(unsigned size, void* state);
// Original: arm9/ov031 @ 0x02203670; symbol: func_ov031_02203670; size: 0x38.
extern "C" void Memory_ProcessBufferedRequest(unsigned size) {
    unsigned char* global = *(unsigned char**)(data_02111304 + 4);
    unsigned char* state = *(unsigned char**)(global + 0xA4);
    if (state == 0) return;
    if (*(unsigned char*)(state + 9) != 0)
        Memory_ReserveBufferedCapacity(size, state);
    else
        ConsumeBufferBytesAndNotify(size, state);
}
