#include <globaldefs.h>
ARM
extern "C" unsigned char MatchesEightBytesAgainstGlobalRecord_TextNWCUSBAP[];
extern "C" int RuntimeMemory_CompareByteRanges(const void *, const void *, unsigned int);
// Original: arm9/ov031 @ 0x022157C4; symbol: func_ov031_022157c4; size: 0x24.
extern "C" int MatchesEightBytesAgainstGlobalRecord(const void *bytes) {
    return RuntimeMemory_CompareByteRanges(bytes, MatchesEightBytesAgainstGlobalRecord_TextNWCUSBAP, 8) == 0;
}
