#include <globaldefs.h>
ARM
struct Pair {unsigned short first,second;};
struct StateBuffer {Pair pair;char remainder[0xac];};
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" Pair TimeRecord_AddCurrentElapsedDuration(Pair,int);
extern "C" {
struct Node { unsigned type; unsigned* nested; };
void Script_WriteIntegerReferenceOutput(Node*,unsigned);
}
// Original: arm9/ov023 @ 0x021E9BE4; symbol: func_ov023_021e9be4; size: 0x70.
// Transforms the two state-header halfwords and writes the first value and low byte of the second to script outputs.
extern "C" int Script_WriteTransformedStatePair(char* output){
 StateBuffer state;GameState_CopyStatisticsRecord(&state);
 Pair result=TimeRecord_AddCurrentElapsedDuration(state.pair,0);
 Script_WriteIntegerReferenceOutput((Node*)output,result.first);
 Script_WriteIntegerReferenceOutput((Node*)(output+8),((unsigned char*)&result)[2]);
 return 1;
}
