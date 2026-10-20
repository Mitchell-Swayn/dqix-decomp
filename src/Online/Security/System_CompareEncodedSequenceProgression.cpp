#include <globaldefs.h>
THUMB
extern "C" unsigned char WirelessSetup_SendCompletionRequest_TextMELCO[];
extern "C" unsigned Util_GetStringLength(const char*);
extern "C" void WirelessSetup_TransformRequestToken(const char*, unsigned, const void*, unsigned);
extern "C" int WirelessSetup_CompareIdentifierBytes(const char*, const char*, unsigned);
extern "C" unsigned WirelessSetup_DecodeNetworkHalfword(unsigned short);
// Original: arm9/ov031 @ 0x0221D7E0; symbol: func_ov031_0221d7e0; size: 0x4C.
extern "C" int System_CompareEncodedSequenceProgression(const char* first, const char* second) {
    int result = 0;
    unsigned value = Util_GetStringLength((const char*)WirelessSetup_SendCompletionRequest_TextMELCO);
    WirelessSetup_TransformRequestToken(second, 8, WirelessSetup_SendCompletionRequest_TextMELCO, value);
    if (WirelessSetup_CompareIdentifierBytes(first, second, 6)) result--;
    else {
        unsigned a = WirelessSetup_DecodeNetworkHalfword(*(unsigned short*)(first + 6));
        unsigned b = WirelessSetup_DecodeNetworkHalfword(*(unsigned short*)(second + 6));
        if (a + 1 != b) result -= 2;
    }
    return result;
}
