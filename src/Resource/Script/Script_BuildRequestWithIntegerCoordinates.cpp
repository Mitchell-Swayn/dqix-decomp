#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20fdd30; symbol: data_020fdd30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Request{unsigned char a,b;short pad;short x,y,z;char tail[6];};extern "C" void ActorPathGraph_ResetNodeLinksAndFlags(Request*);extern "C" void* ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage;extern "C" void ActorPathGraph_AppendNode(void*,Request*);
// Original: arm9/main @ 0x02027CE4; symbol: func_02027ce4; size: 0xB0.
extern "C" ARM int Script_BuildRequestWithIntegerCoordinates(Script::Parameter* p){Request r;ActorPathGraph_ResetNodeLinksAndFlags(&r);r.a=p[0].ToInt();r.b=p[1].ToInt();r.x=((int)(4096.f*p[2].ToFloat()))>>12;r.y=((int)(4096.f*p[3].ToFloat()))>>12;r.z=((int)(4096.f*p[4].ToFloat()))>>12;ActorPathGraph_AppendNode(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage,&r);return 1;}
