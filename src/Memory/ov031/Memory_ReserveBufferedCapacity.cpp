#include <globaldefs.h>
ARM
extern "C" void* data_ov031_0224c9c0;
typedef void (*Callback)(void*);
// Original: arm9/ov031 @ 0x0220A66C; symbol: func_ov031_0220a66c; size: 0x50.
extern "C" void Memory_ReserveBufferedCapacity(unsigned size, void* request) {
    unsigned char* state = *(unsigned char**)((char*)request + 0xC);
    unsigned remaining = *(unsigned*)(state + 0x828) - *(unsigned*)(state + 0x82C);
    if (size < remaining) goto update;
    if (*(Callback*)(state + 0x824) != 0)
        ((Callback)data_ov031_0224c9c0)(*(void**)(state + 0x824));
    *(unsigned*)(state + 0x824) = 0;
    return;
update:
    *(unsigned*)(state + 0x82C) += size;
}
