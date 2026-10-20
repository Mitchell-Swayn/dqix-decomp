#include <globaldefs.h>
ARM
struct Flags { unsigned int low:1;unsigned int active:1;unsigned int high:30; };
// Original: arm9/main @ 0x02085794; symbol: func_02085794; size: 0x2C.
 extern "C" bool CharacterState_TestActiveSpecialExtendedModifierBit1(unsigned char* p) { if (*(short*)(p+0x2ac)<=0)return false;return ((Flags*)(p+0x2f8))->active!=0; }
