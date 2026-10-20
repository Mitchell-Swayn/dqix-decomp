// Cached original field widths and exact relocation-backed calls/globals reviewed.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/Script.h>
#include <System/Matrix.h>
#include <Graphics/VRAMStaging.h>
ARM
#pragma force_active on
// Original data: arm9/main @ 0x20ee798; symbol: data_020ee798.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000c0002000d0003000e0004000f0005001000060011000700120008001300090013000a0013000b001300ffff1300.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee7c8; symbol: data_020ee7c8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000100010002000200030003000400040005000500060006000700070008000800090009000a000a000b000b00ffff000000000000.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108844; symbol: data_02108844.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1180 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109950; symbol: data_02109950.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109a30; symbol: data_02109a30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Triple{int x,y,z;};struct Matrix{unsigned v[12];};struct Transform{Triple a,b,c;Matrix d;};struct Bits{unsigned char a:1,b:7;};struct Packed{unsigned a:10,b:10,c:12;};struct Link{char pad[6];unsigned char kind,rest;unsigned a,b;Link* same;Link* next;};extern "C"{void func_0200f374(void*,unsigned);void LinkedQueue_InitializeNodeStatus(void*);void* GameState_GetObjectWithFlag100(GameState*,int);extern short ScriptFillFirstEightByTwoIntegerTable_UnknownRoleZeroInitializedStorage[8][2],ScriptFillSecondEightByTwoIntegerTable_UnknownRoleZeroInitializedStorage[8][2],ZoneSerializedRecordGetKindIconIndex_UnknownRoleInitializedBytes_Variant2[],ZoneSerializedRecordGetKindIconIndex_UnknownRoleInitializedBytes[];extern Link* ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/main @ 0x020AE398; symbol: func_020ae398; size: 0x5C.
extern "C" void Object3D_LowerPositionAndTwoSavedHeights(char* p){Vector3i v;v=*(Vector3i*)(p+68);v.y-=409;*(Vector3i*)(p+68)=v;*(int*)(p+360)-=409;*(int*)(p+376)-=409;}
