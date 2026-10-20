#include <globaldefs.h>
ARM
struct Flags { unsigned int low:6;unsigned int active:1;unsigned int high:25; };
// Original: arm9/main @ 0x02085180; symbol: func_02085180; size: 0x2C.
 extern "C" bool CharacterState_WeaponPrioritizesEligibleActions(unsigned char* p) { if (*(short*)(p+0x2ac)<=0)return false;return ((Flags*)(p+0x2f4))->active!=0; }
