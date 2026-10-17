#include <globaldefs.h>
ARM
extern "C" {int Network_TestIdentifierAllowedInCurrentMode();int ReadOneOf204PackedTwoBitValues(int,int);unsigned int Object_ReadParitySelectedFlagForBoundedIndex(int,int);
// Original: arm9/main @ 0x0206474C; symbol: func_0206474c; size: 0xF0.
unsigned int Object_TestKindDependentStatus(int a,int b,int kind){if(!Network_TestIdentifierAllowedInCurrentMode())return 0;switch(kind){case -1:return ReadOneOf204PackedTwoBitValues(a,b)==0;case 0:return ReadOneOf204PackedTwoBitValues(a,b)==2;case 1:return Object_ReadParitySelectedFlagForBoundedIndex(a,b);case 2:return ReadOneOf204PackedTwoBitValues(a,b)==3;case 3:return ReadOneOf204PackedTwoBitValues(a,b)==1;case 5:return ReadOneOf204PackedTwoBitValues(a,b)==0;}return 0;}}
