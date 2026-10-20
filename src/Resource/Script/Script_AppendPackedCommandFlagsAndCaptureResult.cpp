#include <Resource/Script.h>
struct Entry { unsigned short id:9; unsigned short flag9:1; unsigned short flag10:1; unsigned short flag11:1; unsigned short flag12:1; unsigned short rest:3; };
struct State { unsigned char pad0; unsigned char skip; unsigned char result; unsigned char pad3[3]; unsigned short count; };
struct Queue { unsigned char pad[0xa8]; volatile Entry *entries; };
// Original data: arm9/main @ 0x20f13d8; symbol: data_020f13d8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109404; symbol: data_02109404.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109418; symbol: data_02109418.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern State ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage; extern Queue QuestGetGlobalOrderState_UnknownRoleZeroInitializedStorage; extern const short QuestExecuteOrderPayloadScript_UnknownRoleInitializedBytes; }
// Original: arm9/main @ 0x02095364; symbol: func_02095364; size: 0x14C.
// Script command appends packed flags and captures the selected command's result.
extern "C" int Script_AppendPackedCommandFlagsAndCaptureResult(Script::Parameter *p) {
 if(ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage.skip) { ++ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage.count; return 1; }
 unsigned short id=p[0].ToInt();
 unsigned short a=p[5].ToInt();
 unsigned short b=p[7].ToInt();
 unsigned short c=p[8].ToInt();
 unsigned short d=p[9].ToInt();
 volatile Entry *entries=QuestGetGlobalOrderState_UnknownRoleZeroInitializedStorage.entries;
 if(entries) {
 unsigned index=ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage.count;
 entries[index].id=id;
 entries[index].flag9=a;
 entries[index].flag11=b;
 entries[index].flag10=c;
 entries[index].flag12=d;
 }
 ++ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage.count;
 if(QuestExecuteOrderPayloadScript_UnknownRoleInitializedBytes>=0 && id==QuestExecuteOrderPayloadScript_UnknownRoleInitializedBytes) ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage.result=c!=0;
 return 1;
}
