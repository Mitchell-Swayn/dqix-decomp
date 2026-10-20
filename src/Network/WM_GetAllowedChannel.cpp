#include <globaldefs.h>
ARM
extern "C" int WirelessCommand_ReadInitializedStatus();
// Original: arm9/main @ 0x020D4AA8; symbol: func_020d4aa8; size: 0x20.
extern "C" unsigned WM_GetAllowedChannel(){if(WirelessCommand_ReadInitializedStatus())return 0x8000;return *(volatile unsigned short*)0x027ffcfa;}
