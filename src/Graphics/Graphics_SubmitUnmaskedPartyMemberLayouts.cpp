#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/main @ 0x20fdc60; symbol: data_020fdc60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20fdcb0; symbol: data_020fdcb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct GameState;struct GameResources;struct Object3D;extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" GameResources* GameResources_GetInstance();extern "C" void* GameState_ReadUnknownB0(GameState*);extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);extern "C" void* Graphics_GetGlobalOamTransferState();extern "C" void* GameState_GetObjectWithFlag100(void*,int);extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);extern "C" void PartyStatus_DrawMemberValueWithDefaultLayout(unsigned,unsigned,int);extern "C" void GameState_InvokePartyMemberRecordLayout(void*,void*,int);extern "C" void WorldMap_SubmitMarkerSprite(char*,unsigned,unsigned,int,unsigned char,unsigned char,unsigned short,unsigned char,unsigned,unsigned);struct Layout{unsigned a,b,c,d;float value;};extern "C" Layout PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage[];struct Entry{int id;unsigned rest[7];};extern "C" Entry GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02027100; symbol: Graphics_SubmitUnmaskedPartyMemberLayouts; size: 0x10C.
extern "C" void Graphics_SubmitUnmaskedPartyMemberLayouts(char* self){void* game=_ZN9GameState11GetInstanceEv();Graphics_GetGlobalOamTransferState();GameResources_GetInstance();for(int i=0;i<B(self,0x75c);i++){unsigned index=B(self+i,0x758);if(B(self,0x75d)&(1<<index))continue;void* object=GameState_GetObjectWithFlag100(game,index);if(!object)continue;if(!GameObject_GetLinkedIndexedState(object))continue;if(GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[index].id<0)continue;Layout* layout=PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage+i;PartyStatus_DrawMemberValueWithDefaultLayout((unsigned)layout,i,index);GameState_InvokePartyMemberRecordLayout(layout,(void*)i,index);unsigned value=(int)layout->value<<12;WorldMap_SubmitMarkerSprite(self,i<<18,value,(unsigned char)(index+1),(unsigned char)(index+60),0,(unsigned short)index,255,4096,4096);}}
