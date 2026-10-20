#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" {
struct Node { unsigned type; unsigned* nested; };
void Script_WriteIntegerReferenceOutput(Node*,unsigned);
}
struct StateBuffer {char pad[0x18];unsigned value:9,other:23;char remainder[0x94];};
// Original: arm9/ov023 @ 0x021E9B48; symbol: func_ov023_021e9b48; size: 0x34.
// Writes the packed nine-bit field at state offset 0x18 to the script output.
extern "C" int Script_ReadStateNineBitValue(Node* output){
 StateBuffer state;GameState_CopyStatisticsRecord(&state);
 Script_WriteIntegerReferenceOutput(output,state.value);return 1;
}
