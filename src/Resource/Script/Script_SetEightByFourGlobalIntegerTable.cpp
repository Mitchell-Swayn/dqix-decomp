#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x2109970; symbol: data_02109970.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short ScriptSetEightByFourGlobalIntegerTable_UnknownRoleZeroInitializedStorage[8][4];
// Original: arm9/main @ 0x02099B7C; symbol: func_02099b7c; size: 0x5C.
extern "C" int Script_SetEightByFourGlobalIntegerTable(Script::Parameter* p){for(int i=0;i<8;i++)for(int j=0;j<4;j++)ScriptSetEightByFourGlobalIntegerTable_UnknownRoleZeroInitializedStorage[i][j]=(p++)->ToInt();return 1;}
