#include <globaldefs.h>
// func_02039d48: 0x02039d48–0x02039d58, arm; 16 bytes
// Original: arm9/main @ 0x02039D48; symbol: func_02039d48; size: 0x10.
extern "C" void GameObject_SuppressPartyRendering(int self) {
    *(unsigned char*)(self + 0x1ce) |= 4;
}
