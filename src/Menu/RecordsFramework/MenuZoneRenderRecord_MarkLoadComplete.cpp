#include <globaldefs.h>
// Original: arm9/ov023 @ 0x021F7320; symbol: func_ov023_021f7320; size: 0xC.
extern "C" ARM void MenuZoneRenderRecord_MarkLoadComplete(void* record) { *(unsigned int*)((unsigned char*)record+0x1c)=2; }
