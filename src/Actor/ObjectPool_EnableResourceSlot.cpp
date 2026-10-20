#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020D76B8; symbol: func_020d76b8; size: 0x20.
extern "C" void ObjectPool_EnableResourceSlot(unsigned char* p,int bit) { if (bit>=0xc0) bit-=0xbc; *(unsigned short*)(p+0xa26)|=1U<<bit; }
