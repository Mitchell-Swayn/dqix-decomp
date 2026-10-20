// Cached exact ARM behavior, header-defined VRAM contracts and original relocation globals reviewed.
#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
#include <GameState/GameState.h>
#include <Resource/Script.h>
ARM
#pragma optimization_level 4
#pragma force_active on
// Original data: arm9/main @ 0x20e7b70; symbol: data_020e7b70.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 040000000d0000002000200040002000200040004000400010001000200020004000400080008000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108ed8; symbol: data_02108ed8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Twelve{unsigned count:12,rest:20;};struct Bit13{unsigned short a:13,flag:1,b:2;};struct Flag21{unsigned a:21,flag:1,b:10;};extern "C"{void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);int WorldMap_FindBackgroundResourceIndex(void*,int);void* GameState_GetObjectWithFlag100(GameState*,int);void* GameObject_GetLinkedIndexedState(void*);int CharacterState_CountCarriedItems(void*);int Network_IsMemberActive(void*,int);int Network_GetAssociationId();char* Network_GetReceivedMemberPacket(void*,int);char* DisplayLayout_GetGroupByIndex(void*,int);extern char NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage[];extern char* ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage[];extern unsigned GraphicsStageImageDataToMappedVRAMRegion_UnknownRoleInitializedBytes[];}
// Original: arm9/main @ 0x02086D20; symbol: func_02086d20; size: 0x68.
extern "C" int GameState_SumListedObjectDerivedValues(unsigned char* p){short n=0;GameState* state=GameState::GetInstance();for(int i=0;i<p[3964];++i){void* q=GameState_GetObjectWithFlag100(state,p[3960+i]);if(q){q=GameObject_GetLinkedIndexedState(q);if(q)n+=CharacterState_CountCarriedItems(q);}}return n;}
