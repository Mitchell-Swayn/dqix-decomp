#include <globaldefs.h>
#include <System/IPC.h>
extern "C" {
// Original: arm9/main @ 0x020D2880; symbol: func_020d2880; size: 0x28.
void IPC_SendARM7CommandSevenUntilAccepted(){do{}while(SendCommandToArm7(7,0,false)<0);}
}
