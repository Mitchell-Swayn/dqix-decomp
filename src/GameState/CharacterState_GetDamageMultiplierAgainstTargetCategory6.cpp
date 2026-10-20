#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020859A0; symbol: func_020859a0; size: 0x38.
extern "C" float CharacterState_GetDamageMultiplierAgainstTargetCategory6(unsigned char* object){if(*(short*)(object+0x2ac)<=0)return 1.0f;int value=(*(int*)(object+0x300)<<14)>>26;return (float)value/10.0f;}
