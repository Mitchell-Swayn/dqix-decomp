#include <globaldefs.h>
ARM
extern "C" unsigned int _fdiv(unsigned int, unsigned int);
extern "C" int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F71D8; symbol: Combat_ComputeNormalizedRecordFields; size: 0x6C.
// Writes two record fields as four times their source floats divided by the unsigned halfword count plus one, then returns 1.
extern "C" int BattleAI_ScaleDamageEstimatesByTargetCount(void *record) {
 unsigned int four = 0x40800000;
 unsigned int first = _fmul(four, *(unsigned int *)((char *)record + 0x14));
 int count1 = *(unsigned short *)((char *)record + 0xc) + 1;
 *(unsigned int *)((char *)record + 0x1c) = _fdiv(first, _fflt(count1));
 unsigned int second = _fmul(four, *(unsigned int *)((char *)record + 0x18));
 int count2 = *(unsigned short *)((char *)record + 0xc) + 1;
 *(unsigned int *)((char *)record + 0x20) = _fdiv(second, _fflt(count2));
 return 1;
}
