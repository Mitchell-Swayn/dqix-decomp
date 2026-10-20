#include <globaldefs.h>
ARM
extern "C" int _Z29IsIPCCommandHandlerRegisteredi7IPCSide(int,int);
extern "C" void _Z24SetArm9IPCCommandHandleriPFvjjjE(int,void(*)(unsigned,unsigned,unsigned));
extern "C" void System_SetGlobalControlByteAndReturnHalfword(unsigned,unsigned,unsigned);
extern "C" int WfcUtility_ExecuteSettingsStorageIpcCommand(int,int,unsigned short,void*);
THUMB
extern "C" void WaitByLoop(unsigned);
ARM
// Original: arm9/ov031 @ 0x0221B6F0; symbol: Network_SendIpcCommandAndInvalidateResponse; size: 0x90.
extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
extern "C" int Network_SendIpcCommandAndInvalidateResponse(int command,unsigned length,void* data) {
 _Z24InvalidateDataCacheRangePKvj(data,length);
 while(!_Z29IsIPCCommandHandlerRegisteredi7IPCSide(4,1)){}
 _Z24SetArm9IPCCommandHandleriPFvjjjE(4,System_SetGlobalControlByteAndReturnHalfword);
 for(;;){if(WfcUtility_ExecuteSettingsStorageIpcCommand(1,command,(unsigned short)length,data)==1)break;WaitByLoop(0x40000);}
 _Z24InvalidateDataCacheRangePKvj(data,length);return 1;
}
