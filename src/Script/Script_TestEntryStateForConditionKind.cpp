#include <globaldefs.h>
ARM
extern "C" {int Network_TestIdentifierAllowedInCurrentMode();int Script_GetPackedEntryState(int,int);unsigned int Script_GetEntryActivationFlagMask(int,int);
// Original: arm9/main @ 0x0206474C; symbol: func_0206474c; size: 0xF0.
unsigned int Script_TestEntryStateForConditionKind(int a,int b,int kind){if(!Network_TestIdentifierAllowedInCurrentMode())return 0;switch(kind){case -1:return Script_GetPackedEntryState(a,b)==0;case 0:return Script_GetPackedEntryState(a,b)==2;case 1:return Script_GetEntryActivationFlagMask(a,b);case 2:return Script_GetPackedEntryState(a,b)==3;case 3:return Script_GetPackedEntryState(a,b)==1;case 5:return Script_GetPackedEntryState(a,b)==0;}return 0;}}
