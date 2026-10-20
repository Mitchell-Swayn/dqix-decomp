#include <globaldefs.h>
extern "C" int Combat_CollectEligiblePartyIds(void*, short*, int, int);
// Original: arm9/ov000 @ 0x02181CBC; symbol: func_ov000_02181cbc; size: 0x48.
extern "C" ARM void Ov000_ConvertFourHalfwordsToWords(void* source, void* unused, int* destination) {
    short temp[4];
    int count = Combat_CollectEligiblePartyIds(source, temp, 4, 0);
    for (int i = 0; i < count; ++i)
        destination[i] = temp[i];
}
