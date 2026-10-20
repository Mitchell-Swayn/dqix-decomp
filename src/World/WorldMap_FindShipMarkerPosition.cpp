// Cached exact ARM behavior, header-defined VRAM contracts and original relocation globals reviewed.
#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
#include <GameState/GameState.h>
#include <Resource/Script.h>
ARM
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
// Original: arm9/main @ 0x02021394; symbol: func_02021394; size: 0x68.
extern "C" int WorldMap_FindShipMarkerPosition(char* p,unsigned a,unsigned b,short* x,short* y){for(int i=0;i<*(unsigned short*)(p+2720);++i){char* q=p+2722+i*8;if(*(unsigned short*)q==a&&(unsigned char)q[2]==b){*x=*(short*)(q+4);*y=*(short*)(q+6);return 1;}}return 0;}
