#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original: arm9/main @ 0x020748F8; symbol: func_020748f8; size: 0x40.
extern "C" float Float_ComputeScaledZeroProduct(float value,unsigned divisor){
    float zero=0.0f;
    float scale=1.0f/(float)divisor;
    zero=zero*value;
    return scale*zero;
}
