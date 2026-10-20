#include <globaldefs.h>
#pragma opt_propagation off
#pragma optimize_for_size off
#include "System/IPC.h"
#include "System/Cache.h"
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"
extern "C" void OS_SpinWait(int);
// Original: arm9/main @ 0x020D0FC4; symbol: func_020d0fc4; size: 0x154.
extern "C" bool CardReadManager_SendSharedCommandWithRetries(volatile unsigned *p,int command,int tries){if(!(p[69]&2)){p[69]|=2;if(!IsIPCCommandHandlerRegistered(11,IPCSide_Arm7)){do{OS_SpinWait(100);}while(!IsIPCCommandHandlerRegistered(11,IPCSide_Arm7));}CardReadManager_SendSharedCommandWithRetries(p,0,1);}CleanInvalidateCacheRange((void *)*p,96);DrainWriteBuffer();int result;do {p[1]=command;p[69]|=32;while(SendCommandToArm7(11,command,true)<0){}if(!command){int address=*p;while(SendCommandToArm7(11,address,true)<0){}}int state=DisableIRQInterrupts();if(p[69]&32){do{BlockCurrentContext(0);}while(p[69]&32);}SetIRQInterruptState(state);InvalidateDataCacheRange((void *)*p,96);result=*(int *)*p;}while(result==4 && --tries>0);return result==0;}
