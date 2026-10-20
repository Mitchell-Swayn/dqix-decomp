#include <globaldefs.h>
extern "C" void GXi_NopClearFifo128_(void*);
// Original: arm9/main @ 0x020C5354; symbol: func_020c5354; size: 0x28.
extern "C" void Graphics_SubmitGeometryAndWaitUntilNotBusy() {GXi_NopClearFifo128_((void*)0x04000400);while(*(volatile unsigned*)0x04000600 & 0x08000000){}}
