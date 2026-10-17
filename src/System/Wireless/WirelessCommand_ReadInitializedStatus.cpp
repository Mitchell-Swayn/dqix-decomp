#include <globaldefs.h>
extern "C" {
extern unsigned short data_021142e0[];
// Original: arm9/main @ 0x020D41E8; symbol: func_020d41e8; size: 0x1C.
int WirelessCommand_ReadInitializedStatus(){if(data_021142e0[0]!=0)return 0;else return 3;}
}
