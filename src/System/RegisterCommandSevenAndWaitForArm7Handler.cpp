#include <globaldefs.h>
ARM
#include <System/IPC.h>
extern "C" void SoundCommand_ReleaseRecordByIdAtomically(unsigned,unsigned,unsigned);extern "C" int ProbeHardwareRegisterUnderIRQProtection();extern "C" void OS_SpinWait(unsigned);
// Original: arm9/main @ 0x020D2820; symbol: func_020d2820; size: 0x60.
extern "C" void RegisterCommandSevenAndWaitForArm7Handler(){SetArm9IPCCommandHandler(7,SoundCommand_ReleaseRecordByIdAtomically);if(!ProbeHardwareRegisterUnderIRQProtection())return;if(!IsIPCCommandHandlerRegistered(7,IPCSide_Arm7)){do{OS_SpinWait(100);}while(!IsIPCCommandHandlerRegistered(7,IPCSide_Arm7));}}
