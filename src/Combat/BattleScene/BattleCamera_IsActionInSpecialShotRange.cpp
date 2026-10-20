#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0216F728; symbol: func_ov000_0216f728; size: 0x24.
// Tests whether a non-null action record has an action code from 9 through 11.
extern "C" int BattleCamera_IsActionInSpecialShotRange(const unsigned short* action) {
 int result = false;
 if(action) result=(unsigned)(*action-9)<=2;
 return result;
}
