#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02085818; symbol: func_02085818; size: 0x38.
extern "C" float CharacterState_GetDamageMultiplierAgainstTargetCategory2(unsigned char* object){if(*(short*)(object+0x2ac)<=0)return 1.0f;int value=(*(int*)(object+0x2fc)<<26)>>26;return (float)value/10.0f;}
