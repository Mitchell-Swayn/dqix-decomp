#include <globaldefs.h>

// Original: arm9/ov024 @ 0x021DB358; symbol: func_ov024_021db358; size: 0x4C.
extern "C" ARM float ComputeRecordHalfwordRatioOrZero(unsigned char* p)
{
    unsigned short* record=*(unsigned short**)(p+0x138);
    unsigned short numerator=record[0];
    if((float)numerator==0.0f) return 0.0f;
    return (float)numerator/(float)record[2];
}
