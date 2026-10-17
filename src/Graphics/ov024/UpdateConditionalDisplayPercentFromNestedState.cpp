#include <globaldefs.h>
ARM
struct Flags {unsigned pad:7;unsigned percent:7;unsigned rest:18;};
extern "C" {bool AreWordFlagBitsZeroAndTwentyFourClear(unsigned*);int TestFlag2AndModeTwo(void*);void CacheSelectedByteEntry(void*,int);void SubmitPercentScaledDisplayRecord(void*,float,unsigned char);}
// Original: arm9/ov024 @ 0x021FD358; symbol: func_ov024_021fd358; size: 0x98.
extern "C" void UpdateConditionalDisplayPercentFromNestedState(char* p){
char* object=*(char**)(p+0x668);
if(!AreWordFlagBitsZeroAndTwentyFourClear(*(unsigned**)(object+0x138)))return;
if(TestFlag2AndModeTwo(*(void**)(object+0x138)))return;
float base=(float)((Flags*)(*(char**)(p+0x64c)+0x14))->percent;
float amount=base*((float)(unsigned)(*(unsigned char*)(*(char**)(object+0x138)+0x4d))/100.0f);
if(amount>100.0f)amount=100.0f;
CacheSelectedByteEntry(p,1);
SubmitPercentScaledDisplayRecord(p,amount,2);
}
