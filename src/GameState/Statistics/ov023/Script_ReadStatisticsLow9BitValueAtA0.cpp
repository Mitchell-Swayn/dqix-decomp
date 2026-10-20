#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" { struct Node { unsigned type;unsigned* nested; }; }
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" void Script_WriteIntegerReferenceOutput(Node*,unsigned);
struct PackedStateProjection { char prefix[0xa0]; unsigned value:9;unsigned remainder:23;char tail[0xc]; };
// Original: arm9/ov023 @ 0x021EACD8; symbol Script_ReadStatisticsLow9BitValueAtA0; size 0x34.
// The packed field is the low nine bits of word A0; higher-level meaning is unresolved.
extern "C" int Script_ReadStatisticsLow9BitValueAtA0(Node* node) {
 PackedStateProjection state;
 GameState_CopyStatisticsRecord(&state);
 Script_WriteIntegerReferenceOutput(node,state.value);
 return 1;
}
