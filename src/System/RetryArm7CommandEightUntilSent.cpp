#include <globaldefs.h>
#include <System/IPC.h>
extern "C" {
// Original: arm9/main @ 0x020CE870; symbol: func_020ce870; size: 0x2C.
void RetryArm7CommandEightUntilSent(int a){do{}while(SendCommandToArm7(8,a,false)!=0);}
}
