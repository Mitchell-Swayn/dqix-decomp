#include <globaldefs.h>
ARM
extern "C" void func_ov017_021d23ec(void*, unsigned short*, void*, char*);
// Original: arm9/ov017 @ 0x021D23EC; symbol: func_ov017_021d23ec; size: 0x14.
extern "C" void func_ov017_021d23ec(void* a, unsigned short* b, void* c, char* d) { (void)a; (void)c; unsigned short v = b[2]; char* q = d + 0x370c; *(unsigned short*)(*(unsigned int*)q + 0x24) = v; }
