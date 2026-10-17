#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void Object_ClearAnimationValuesAndInitializeIdentityMatrix(void*);
// Original: arm9/main @ 0x02056D10; symbol: func_02056d10; size: 0x70.
extern "C" void ResetRecordCountersFlagsAndThreeVectorBuffers(unsigned char* p){Object_ClearAnimationValuesAndInitializeIdentityMatrix(p);*(int*)(p+0x30)=0;*(int*)(p+0x2c)=0;*(int*)(p+0x28)=0;p[0xc]=0;p[0x39]=0;p[0x3a]=0;p[0x3b]=0;*(int*)(p+0x40)=0;*(int*)(p+0x44)=0;*(int*)(p+0x48)=0;*(int*)(p+0x154)=0;*(int*)(p+0x34)=0;memset(p+0xc4,0,12);memset(p+0xd0,0,12);memset(p+0xdc,0,12);}
