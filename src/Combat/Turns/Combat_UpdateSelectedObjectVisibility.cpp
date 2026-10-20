#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" char* GameState_FindIndexedObjectWithFlag400(void*,unsigned);
extern "C" void _ZN8Object3D11MakeVisibleEv(void*);
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);
extern "C" int CombatantMotion_GetActiveStatus(char*);
extern "C" unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);
extern "C" void ObjectPool_EnableResourceSlot(unsigned char*,int);
extern "C" void ObjectPool_DisableResourceSlot(char*,int);
extern "C" int Combat_ClassifySpecialEncounterSpecies(unsigned char*);
extern "C" void* BattleScene_ResolveCurrentActionRecord(char*);
extern "C" int Combat_DispatchSelectionProcedure(void*,void*,int,int*);
struct ComponentFlags { unsigned a:27, hidden:1, b:4; };
// Original: arm9/ov000 @ 0x021626A0; symbol: func_ov000_021626a0; size: 0x15C.
extern "C" void Combat_UpdateSelectedObjectVisibility(char* self,int selection,int visible) {
 void* game=_ZN9GameState11GetInstanceEv();
 char* obj;
 int show;
 unsigned char* record=*(unsigned char**)(self+0x29c);
 char* owner=*(char**)(self+0xea4);
 void* resolved=BattleScene_ResolveCurrentActionRecord(self);
 if(owner) {
 int ids[16];
 int count=Combat_DispatchSelectionProcedure(*(void**)(self+0x29c),resolved,selection,ids);
 for(int i=0;i<count;i++) {
 obj=_ZN9GameState20GetGameObjectByIndexEi(game,ids[i]);
 if(obj) {
 show=visible;
 if(*(unsigned short*)obj&0x400) {
 char* flagged=GameState_FindIndexedObjectWithFlag400(game,ids[i]);
 if(flagged) {
 char* component=*(char**)(flagged+0x148);
 if(!CombatantMotion_GetActiveStatus(flagged)) {
 if(((ComponentFlags*)(component+0x10))->hidden) show=0;
 }
 }
 }
 if(show) {
 _ZN8Object3D11MakeVisibleEv(obj);
 ObjectPool_EnableResourceSlot((unsigned char*)owner,ids[i]);
 } else {
 _ZN8Object3D10MakeHiddenEv(obj);
 ObjectPool_DisableResourceSlot(owner,ids[i]);
 }
 }
 }
 if(Combat_ClassifySpecialEncounterSpecies(record)) {
 for(show=1;show<4;show++) {
 obj=_ZN9GameState20GetGameObjectByIndexEi(game,show);
 if(obj && PartySelection_GetMemberMask(*(unsigned char**)(self+0x2a0),(unsigned char)show)) {
 _ZN8Object3D10MakeHiddenEv(obj);
 ObjectPool_DisableResourceSlot(owner,show);
 }
 }
 }
 }
}
