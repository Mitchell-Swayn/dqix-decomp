#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void InitializeGlobalInterruptFourStateOnce(void);
extern "C" void Object_ClearElement0AndClearElement2AndClearElement8(void *);
extern "C" void ConfigurePeriodicScanlineAlarmUnderIRQProtection(void *, int, int, unsigned int, int);
extern "C" void RunConditionalUpdateWithResourceMutexTemporarilyDisabled(void);
// Original: arm9/main @ 0x020DB228; symbol: func_020db228; size: 0x3C.
extern "C" void Timer_ConfigureObjectRecordFor225And30(int object, unsigned int, unsigned int, unsigned int arg4) {
    InitializeGlobalInterruptFourStateOnce();
    Object_ClearElement0AndClearElement2AndClearElement8((char *)object + 0x14);
    ConfigurePeriodicScanlineAlarmUnderIRQProtection((char *)object + 0x14, 0xe1, 0x1e, (unsigned int)RunConditionalUpdateWithResourceMutexTemporarilyDisabled, object);
}
