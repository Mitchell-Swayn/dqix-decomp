#include <globaldefs.h>
THUMB
extern "C" unsigned char *WirelessSetup_AppendAlignedTaggedField(unsigned char *);
// Original: arm9/ov031 @ 0x022203F0; symbol: func_ov031_022203f0; size: 0x28.
extern "C" int Resource_InitializeAndMeasurePayload(unsigned char *buffer) {
    buffer[0] = 0; buffer[1] = 0; buffer[2] = 0; buffer[3] = 0;
    buffer[4] = 0; buffer[5] = 0; buffer[6] = 0; buffer[7] = 0;
    unsigned char *end = WirelessSetup_AppendAlignedTaggedField(buffer + 8);
    int totalLength = (int)(end - buffer);
    *(unsigned short *)buffer = (unsigned short)(totalLength - 8);
    return totalLength;
}
