#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02085968; symbol: func_02085968; size: 0x38.
extern "C" float CharacterState_GetDamageMultiplierAgainstTargetCategory1(unsigned char* object){if(*(short*)(object+0x2ac)<=0)return 1.0f;int value=(*(int*)(object+0x300)<<20)>>26;return (float)value/10.0f;}
