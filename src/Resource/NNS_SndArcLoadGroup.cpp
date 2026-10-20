#include <globaldefs.h>

extern "C" int NNSi_SndArcLoadGroup();

// Original: arm9/main @ 0x020BDC80; symbol: func_020bdc80; size: 0x18.
extern "C" ARM bool NNS_SndArcLoadGroup() {
    return NNSi_SndArcLoadGroup() == 0;
}
