#include <globaldefs.h>
ARM
extern "C" int WM_MeasureChannel(int, unsigned short, unsigned short, unsigned short, unsigned short);
// Original: arm9/ov031 @ 0x02239E48; symbol: func_ov031_02239e48; size: 0x20.
extern "C" int WirelessHost_MeasureChannelWithFixedSurveyParameters(int first, unsigned short fourth) {
    return WM_MeasureChannel(first, 3, 0x11, fourth, 0x1e);
}
