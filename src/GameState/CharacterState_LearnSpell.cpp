#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02083B60; symbol: func_02083b60; size: 0x2C.
extern "C" void CharacterState_LearnSpell(unsigned char* p,int bit) { unsigned char* bits=p+0x910;bits[bit/8]|=1U<<(bit%8); }
