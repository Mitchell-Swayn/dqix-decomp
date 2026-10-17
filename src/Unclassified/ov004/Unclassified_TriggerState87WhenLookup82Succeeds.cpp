#include <globaldefs.h>
ARM
extern "C" void *func_ov004_0215e47c(void *, unsigned);
extern "C" void Graphics_DecrementActiveRecordAngle(void *, void *);
extern "C" void InvokeEntryHandlerForStateKey(void *, unsigned, unsigned);
// Original: arm9/ov004 @ 0x02162B04; symbol: func_ov004_02162b04; size: 0x38.
extern "C" int Unclassified_TriggerState87WhenLookup82Succeeds(void *arg) {
    void *result = func_ov004_0215e47c(arg, 0x82);
    if (result != 0) {
        Graphics_DecrementActiveRecordAngle(result, arg);
        InvokeEntryHandlerForStateKey(arg, 0x87, 1);
    }
    return 0;
}
