#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020863C4; symbol: func_020863c4; size: 0x1C.
void CharacterState_ClearFlagsAndRestoreHealthAndMagic(char *p){*(int *)(p+24)=0;*(unsigned short *)(p+28)=*(unsigned short *)(p+0x6c);*(unsigned short *)(p+30)=*(unsigned short *)(p+0x6e);}
}
