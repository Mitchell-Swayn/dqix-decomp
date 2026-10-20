#include <globaldefs.h>
struct Ratios { unsigned char p[8]; short denominator; short p2; short numerator; };
#pragma force_active on
// Original: arm9/ov000 @ 0x02170C7C; symbol: func_ov000_02170c7c; size: 0x7C.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" int BattleHud_ClassifyHealthRatio(Ratios* self)
{
    int result=0; short d=self->denominator; if (d==0) return 6; float ratio=(float)self->numerator/(float)d; if (ratio <= 0.0f) result=6; else if (ratio <= 0.08f) result=5; else if (ratio <= 0.25f) result=4; return result;
}
