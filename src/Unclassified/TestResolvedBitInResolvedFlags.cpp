#include <globaldefs.h>
extern "C" unsigned int Object_FindSignedByteKeyInSixteenEntries();
extern "C" unsigned int ReadCurrentStateHalfwordFromAvailableRepresentation(unsigned int);
// Original: arm9/main @ 0x0202BD34; symbol: func_0202bd34; size: 0x34.
extern "C" int TestResolvedBitInResolvedFlags(unsigned int value) {
    unsigned int bit = Object_FindSignedByteKeyInSixteenEntries();
    int result;
    if ((int)bit < 0) {
        result = 0;
    } else {
        unsigned int flags = ReadCurrentStateHalfwordFromAvailableRepresentation(value);
        result = 1;
        if ((flags & (1u << bit)) == 0) result = 0;
    }
    return result;
}
