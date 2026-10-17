#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 2
#pragma opt_common_subs off
#pragma opt_rebuildlogicals off
#pragma opt_propagation off
extern "C" int IsFirstValueNonzero(int*);
// Original: arm9/main @ 0x0202EEB4; symbol: func_0202eeb4; size: 0x50.
 extern "C" int Object_TestAnyOfThreeEmbeddedRecordsActive(char* p){int result=1;int found=1;if(IsFirstValueNonzero((int*)(p+0x16c))==0){if(IsFirstValueNonzero((int*)(p+0x194))==0)found=0;}if(found==0){if(IsFirstValueNonzero((int*)(p+0x1bc))==0)result=0;}return result;}
