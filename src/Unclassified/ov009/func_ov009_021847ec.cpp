#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" int FindIndexedBinaryKeyByLengthComparison(const char*,int);
extern "C" const char data_ov009_0218aafc[15][5];
struct CharacterFilter { char unknown[0x18]; int cleared[3]; int count; short flags; unsigned char enabled[15]; };
// Original: arm9/ov009 @ 0x021847EC; symbol: func_ov009_021847ec; size: 0x5C.
extern "C" void func_ov009_021847ec(CharacterFilter* state) {
 memset(state->cleared,0,12);state->count=0;state->flags=0;
 unsigned char* enabled=state->enabled;for(int i=0;i<15;i++) *enabled++=FindIndexedBinaryKeyByLengthComparison(data_ov009_0218aafc[i],1);
}
