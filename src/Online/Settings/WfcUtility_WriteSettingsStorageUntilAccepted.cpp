#include <globaldefs.h>
ARM
extern "C" int _Z29IsIPCCommandHandlerRegisteredi7IPCSide(int,int);
extern "C" void _Z24SetArm9IPCCommandHandleriPFvjjjE(int,void(*)(unsigned,unsigned,unsigned));
extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned);
extern "C" void System_SetGlobalControlByteAndReturnHalfword(unsigned,unsigned,unsigned);
extern "C" int WfcUtility_ExecuteSettingsStorageIpcCommand(int,unsigned,unsigned,void*);
extern "C" void WaitByLoop(unsigned);
// Original: arm9/ov031 @ 0x0221B780; symbol: SendCacheCleanedIpcTransferUntilAccepted; size: 0x7c.
// Waits for remote IPC4 handler, installs local callback, cleans buffer, retries command2 until accepted.
extern "C" void WfcUtility_WriteSettingsStorageUntilAccepted(unsigned arg,unsigned length,void* buffer){
 while(!_Z29IsIPCCommandHandlerRegisteredi7IPCSide(4,1)){}
 _Z24SetArm9IPCCommandHandleriPFvjjjE(4,System_SetGlobalControlByteAndReturnHalfword);
 _Z15CleanCacheRangePKvj(buffer,length);
 for(;;){if(WfcUtility_ExecuteSettingsStorageIpcCommand(2,arg,length,buffer)==1)return;WaitByLoop(0x40000);}
}
