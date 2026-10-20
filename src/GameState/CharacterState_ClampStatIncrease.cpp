#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02084E4C; symbol: func_02084e4c; size: 0x2C.
int CharacterState_ClampStatIncrease(int unused,unsigned int start,unsigned int len,unsigned int end){unsigned int sum=start+len;if(start==end)len=0;else if(start>end)len=0;else if(sum>end)len=end-start;return len;}
}
