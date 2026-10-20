#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02083CA0; symbol: func_02083ca0; size: 0x1C.
void CharacterState_SelectAndUnlockVocation(char *p,unsigned int i){*(unsigned short *)(p+0x954)|=1<<i;*(unsigned int *)(p+0x950)=i;}
}
