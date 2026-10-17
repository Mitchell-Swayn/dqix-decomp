#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0202A91C; symbol: func_0202a91c; size: 0x28.
extern "C" void SetByteField6CAndInvokeCallbackOnce(unsigned char* p){if(p[108]!=1){p[108]=1;void(*callback)(void*)=*(void(**)(void*))(p+124);if(callback)callback(p);}}
