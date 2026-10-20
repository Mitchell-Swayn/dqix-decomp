// Exact original ARM fields, relocation targets and named allocator/Object3D contracts reviewed.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
#include <Memory/SignedAllocator.h>
#include <System/Interrupts.h>
ARM
#pragma force_active on
// Original data: arm9/main @ 0x20fe9cc; symbol: data_020fe9cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210f3d8; symbol: data_0210f3d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21117ec; symbol: data_021117ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111808; symbol: data_02111808.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2112780; symbol: data_02112780.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Entry{unsigned word;unsigned char a,b,c,pad;};struct Node{unsigned a,b;Node* next;};struct Nine{unsigned v[9];};struct Three{unsigned v[3];};struct Large{Nine a;Three b;unsigned c;};struct Bits{unsigned char a:1,b:1,c:1,d:1,rest:4;};struct Buffer{unsigned length;unsigned char* data;};extern "C"{int Network_FindWirelessSlotByMemberId(void*,int);int Network_FindPreviousWirelessSlotByMemberId(void*,int);void* GameState_GetObjectWithFlag100(GameState*,int);char* GameObject_GetLinkedIndexedState(void*);int Vocation_TestEquipmentCategory(unsigned,void*);unsigned PartySelection_GetMemberMask(void*,unsigned);char* PartySync_FindSelectedEntryForMember(void*,int);void Network_RecordWirelessErrorUnlessTerminal(unsigned);Object3D* GameState_FindIndexedObjectWithFlag1000(GameState*,int);extern char DebugTextWriteTileString_UnknownRoleZeroInitializedStorage[],SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage[];extern unsigned SNDPushCommand_UnknownRoleZeroInitializedStorage[],PMGoSleepMode_UnknownRoleZeroInitializedStorage[],IPCWaitForPendingCommandCompletion_UnknownRoleZeroInitializedStorage[],NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];}void HandleCommandReceivedFromArm7();
// Original: arm9/main @ 0x0204166C; symbol: func_0204166c; size: 0x54.
extern "C" void TextEntry_ResetGlyphRenderRecord(char* p){*(int*)p=0;*(int*)(p+4)=0;*(int*)(p+8)=-1;*(int*)(p+12)=0;*(int*)(p+16)=0;*(short*)(p+20)=0;*(int*)(p+24)=0;((Bits*)(p+22))->a=0;((Bits*)(p+22))->b=0;((Bits*)(p+22))->c=0;((Bits*)(p+22))->d=0;p[23]=0;}
