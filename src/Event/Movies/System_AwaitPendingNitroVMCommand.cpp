#include <globaldefs.h>
ARM
extern "C" void _Z30NitroVM_AwaitCommandCompletionP7NitroVM(void*);
// Original: arm9/ov016 @ 0x0218F678; symbol: func_ov016_0218f678; size: 0x28.
extern "C" void System_AwaitPendingNitroVMCommand(unsigned char* p) { if (p[0x10] == 1) _Z30NitroVM_AwaitCommandCompletionP7NitroVM(*(void**)(p + 0xc)); p[0x10] = 0; }
