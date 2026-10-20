#include <globaldefs.h>
ARM
#pragma opt_scalarize off
#pragma opt_dead_assignments off
#include <Resource/Script.h>
// Original data: arm9/ov031 @ 0x2291e04; symbol: data_ov031_02291e04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[];
struct IntegerValue {int value;IntegerValue(int input):value(input){} operator int()const{return value;}};
// Original: arm9/ov031 @ 0x02243300; symbol: func_ov031_02243300; size: 0x48.
extern "C" int Script_SetIndexedNetworkWord(Script::Parameter* parameters){int index=parameters[0].ToInt();if(index<0||index>=14)return 1;IntegerValue value(parameters[1].ToInt());(*(int**)(ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage+0x28))[index]=value;return 1;}
