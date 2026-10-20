#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" {
struct Node { unsigned type; unsigned* nested; };
void Script_WriteIntegerReferenceOutput(Node*,unsigned);
}
struct StateBuffer {char pad[0x34];unsigned value:24,other:8;char remainder[0x78];};
// Original: arm9/ov023 @ 0x021E9D2C; symbol: func_ov023_021e9d2c; size: 0x34.
// Writes the packed 24-bit field at state offset 0x34 to the script output.
extern "C" int Script_ReadStateTwentyFourBitValue(Node* output){
 StateBuffer state;GameState_CopyStatisticsRecord(&state);
 Script_WriteIntegerReferenceOutput(output,state.value);return 1;
}
