#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02085A80; symbol: func_02085a80; size: 0x38.
extern "C" float CharacterState_GetDamageMultiplierAgainstTargetCategory10(unsigned char* object){if(*(short*)(object+0x2ac)<=0)return 1.0f;return (float)((*(int*)(object+0x304)<<20)>>26)/10.0f;}
