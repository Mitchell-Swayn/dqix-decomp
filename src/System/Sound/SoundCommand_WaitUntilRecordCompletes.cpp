#include "globaldefs.h"
#pragma optimize_for_size off
ARM
extern "C" int TestWraparoundTargetCounterUnderIRQGuard(void*); extern "C" int func_020d22f4(int); extern "C" void IPC_SendARM7CommandSevenUntilAccepted();
// Original: arm9/main @ 0x020D2680; symbol: func_020d2680; size: 0x6C.
extern "C" void SoundCommand_WaitUntilRecordCompletes(void*p){if(TestWraparoundTargetCounterUnderIRQGuard(p))return;while(func_020d22f4(0)){}if(TestWraparoundTargetCounterUnderIRQGuard(p))return;IPC_SendARM7CommandSevenUntilAccepted();if(TestWraparoundTargetCounterUnderIRQGuard(p))return;do{func_020d22f4(1);}while(!TestWraparoundTargetCounterUnderIRQGuard(p));}
