#include <globaldefs.h>

ARM
// Original: arm9/ov017 @ 0x021B2038; symbol: func_ov017_021b2038; size: 0x14.
extern "C" unsigned int OnlineDownload_GetTransferSubstate(void *self) { void *nested=*(void **)((unsigned char *)self+0x24); return nested ? *((unsigned char *)nested+0x35) : 0; }
