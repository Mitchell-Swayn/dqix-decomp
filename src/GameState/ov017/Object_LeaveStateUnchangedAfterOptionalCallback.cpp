#include <globaldefs.h>
ARM
extern "C" void func_ov008_02184878(signed char *);
extern "C" void Object_LeaveStateUnchanged(void *);

// Original: arm9/ov017 @ 0x021B9904; symbol: func_ov017_021b9904; size: 0x24.
extern "C" void Object_LeaveStateUnchangedAfterOptionalCallback(void *object) {
    signed char *callbackObject = *(signed char **)((unsigned char *)object + 0x118);
    if (callbackObject != 0)
        func_ov008_02184878(callbackObject);
    Object_LeaveStateUnchanged((unsigned char *)object + 0x30);
}
