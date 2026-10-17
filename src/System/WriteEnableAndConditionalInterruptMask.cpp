#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" int data_02112148; extern "C" int TestFirstReadinessPredicateAndNegatedSecondPredicate(); extern "C" void OS_SetDPermissionsForProtectionRegion(unsigned,unsigned);
// Original: arm9/main @ 0x020D15B4; symbol: func_020d15b4; size: 0x48.
extern "C" void WriteEnableAndConditionalInterruptMask(int enable) { int state=DisableIRQInterrupts(); data_02112148=enable; if(!TestFirstReadinessPredicateAndNegatedSecondPredicate())OS_SetDPermissionsForProtectionRegion(0xf000,enable?0x1000:0x5000); SetIRQInterruptState(state); }
