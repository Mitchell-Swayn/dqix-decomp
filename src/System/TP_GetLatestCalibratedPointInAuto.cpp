#include <globaldefs.h>

extern "C" void TP_GetLatestRawPointInAuto(void*);
extern "C" void TouchInput_CalibrateAndClampSample(void*, void*);

// Original: arm9/main @ 0x020CDDC0; symbol: func_020cddc0; size: 0x1C.
extern "C" ARM void TP_GetLatestCalibratedPointInAuto(void* object) {
    TP_GetLatestRawPointInAuto(object);
    TouchInput_CalibrateAndClampSample(object, object);
}
