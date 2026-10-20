#include <globaldefs.h>
THUMB
extern "C" int WirelessSetup_DecodeNetworkHalfword(unsigned int);
extern "C" void System_Copy8WithReversedPointers(void *destination, const void *source, unsigned int length);
// Original: arm9/ov031 @ 0x0221DB18; symbol: func_ov031_0221db18; size: 0x30.
extern "C" int WirelessSetup_CopyTaggedConfigurationPayload(void *object, void *destination) {
    unsigned char *record = (unsigned char *)object + 6;
    int length = WirelessSetup_DecodeNetworkHalfword(*(unsigned short *)(record + 2));
    if (length <= 0)
        return -1;
    if (record[0] != 0x70)
        return -1;
    System_Copy8WithReversedPointers(destination, record + 6, length);
    return 0;
}
