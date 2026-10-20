#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02170460; symbol: BattleHud_AdvanceSelectedSlotPulse; size: 0x78.
// For active records, advances float at0x40 by0.2 per positive step under flag8 and caps it at original IEEE0x40490FDA.
// Clears the float when flag8 is absent; field semantics remain unresolved.
extern "C" void BattleHud_AdvanceSelectedSlotPulse(unsigned char* self,int step)
{
    if (*(int*)(self+0x4c)<0) return;
    if (step<=0) step=1;
    if (self[0x24]&8) {
        *(float*)(self+0x40) += 0.2f*step;
        if (3.141592502593994140625f < *(float*)(self+0x40))
            *(float*)(self+0x40)=3.141592502593994140625f;
    } else *(float*)(self+0x40)=0.0f;
}
