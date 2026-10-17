#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
int WirelessCommand_ReadInitializedStatus();extern unsigned int *data_021142e0[];
// Original: arm9/main @ 0x020D46A8; symbol: func_020d46a8; size: 0x24.
unsigned int ReadSharedValueWhenOperationReady(){if(WirelessCommand_ReadInitializedStatus())return 0;return data_021142e0[1][1];}
}
