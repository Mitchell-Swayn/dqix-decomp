#include <globaldefs.h>
ARM
struct Flags { unsigned int low:29;unsigned int active:1;unsigned int high:2; };
// Original: arm9/main @ 0x020856C8; symbol: func_020856c8; size: 0x2C.
 extern "C" bool CharacterState_TestActiveSpecialPrimaryModifierBit29(unsigned char* p) { if (*(short*)(p+0x2ac)<=0)return false;return ((Flags*)(p+0x2f4))->active!=0; }
