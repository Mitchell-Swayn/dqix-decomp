#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2108ee8; symbol: data_02108ee8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State {char pad[12];unsigned char* p;};extern "C" State CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x02082410; symbol: func_02082410; size: 0x6C.
extern "C" ARM int Script_WriteSeventeenValuesAndFiveDefaults(Script::Parameter* p){for(int i=0;i<17;i++){unsigned char v=p->ToInt();p++;(CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage.p+i)[60]=v;}for(int i=17;i<22;i++)(CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage.p+i)[60]=100;return 1;}
