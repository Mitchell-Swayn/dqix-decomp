#include <globaldefs.h>

#pragma force_active on
// Original: arm9/ov024 @ 0x021DA644; symbol: func_ov024_021da644; size: 0x2C.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int index, int yes, int no)
{
    int valid=index >= 0 && index <= 3; return valid ? (unsigned short)(unsigned)yes : (unsigned short)(unsigned)no;
}
