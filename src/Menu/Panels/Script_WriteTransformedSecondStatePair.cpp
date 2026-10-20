#include <globaldefs.h>
ARM
struct Pair {unsigned short first,second;};
struct StateBuffer {Pair pair[2];char remainder[0xa8];};
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" Pair TimeRecord_AddCurrentElapsedDuration(Pair,int);
extern "C" {
struct Node { unsigned type; unsigned* nested; };
void Script_WriteIntegerReferenceOutput(Node*,unsigned);
}
// Original: arm9/ov023 @ 0x021E9C54; symbol: func_ov023_021e9c54; size: 0x70.
// Transforms the second pair of state-header halfwords and writes the first value and low byte of the second to script outputs.
extern "C" int Script_WriteTransformedSecondStatePair(char* output){
 StateBuffer state;GameState_CopyStatisticsRecord(&state);
 Pair result=TimeRecord_AddCurrentElapsedDuration(state.pair[1],1);
 Script_WriteIntegerReferenceOutput((Node*)output,result.first);
 Script_WriteIntegerReferenceOutput((Node*)(output+8),((unsigned char*)&result)[2]);
 return 1;
}
