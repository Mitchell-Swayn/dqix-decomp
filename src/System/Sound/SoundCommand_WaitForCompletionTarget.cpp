#include "globaldefs.h"
#pragma optimize_for_size off
ARM
extern "C" int TestWraparoundTargetCounterUnderIRQGuard(void*); extern "C" int SoundCommand_ReclaimCompletedBatch(int); extern "C" void IPC_SendARM7CommandSevenUntilAccepted();
// Original: arm9/main @ 0x020D2680; symbol: func_020d2680; size: 0x6C.
extern "C" void SoundCommand_WaitForCompletionTarget(void*p){if(TestWraparoundTargetCounterUnderIRQGuard(p))return;while(SoundCommand_ReclaimCompletedBatch(0)){}if(TestWraparoundTargetCounterUnderIRQGuard(p))return;IPC_SendARM7CommandSevenUntilAccepted();if(TestWraparoundTargetCounterUnderIRQGuard(p))return;do{SoundCommand_ReclaimCompletedBatch(1);}while(!TestWraparoundTargetCounterUnderIRQGuard(p));}
