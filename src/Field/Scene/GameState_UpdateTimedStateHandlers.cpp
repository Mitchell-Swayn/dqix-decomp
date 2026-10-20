#include <globaldefs.h>
ARM
struct Object;struct GameState;struct GameResources;struct MapGameObject;struct E;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void GameObject_DisableMovementInput(Object*,int);
extern "C" void* GameState_GetFieldOrbitCamera(GameState*);
extern "C" void Camera_DisableTargetFollowing(int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void GameResources_SetSecondaryFlags(int,unsigned);
extern "C" void GameObject_RequestMovementInputEnable(int);
extern "C" void Camera_EnableTargetFollowing(int);
extern "C" void GameResources_ClearSecondaryFlags(int,unsigned);
extern "C" void Resource_PollNestedLoaderIfPresent(void*);
extern "C" int LinkedList_ContainsNodeByIdentity(E**,E*);
extern "C" void Memory_DestroyTwoAllocatorsAndRestoreGameFlags(void*);
struct Handlers {int (*functions[7])(unsigned char*);};
// Original data: arm9/ov017 @ 0x21d6c04; symbol: data_ov017_021d6c04.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex ec5a1b02885c1b02f85c1b02c45d1b02005f1b02c05f1b0200000000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Handlers GameStateUpdateTimedStateHandlers_UnknownRoleProcedureReferenceRecords;
// Original: arm9/ov017 @ 0x021B58B8; symbol: func_ov017_021b58b8; size: 0x16C.
extern "C" void GameState_UpdateTimedStateHandlers(unsigned char* self,E** list) {
 if(*(unsigned short*)(self+0x18)) {
  void* game=_ZN9GameState11GetInstanceEv();
  unsigned char* object=(unsigned char*)_ZN9GameState20GetUnknownGameObjectEv(game);
  if(object) {
   unsigned elapsed=_ZNK9GameState21GetEffectiveDeltaTimeEv(game);
   if(elapsed<*(unsigned short*)(self+0x18)) {
    GameObject_DisableMovementInput((Object*)object,1);
    *(short*)(object+0xb2)=0;
    *(unsigned short*)(self+0x18)-=elapsed;
    void* secondary=GameState_GetFieldOrbitCamera((GameState*)game);
    if(secondary) Camera_DisableTargetFollowing((int)secondary);
    GameResources* resources=GameResources_GetInstance();
    if(resources) GameResources_SetSecondaryFlags((int)resources,0x80);
   } else if(!self[0x54]) {
    GameObject_RequestMovementInputEnable((int)object);
    *(unsigned short*)(self+0x18)=0;
    void* secondary=GameState_GetFieldOrbitCamera((GameState*)game);
    if(secondary) Camera_EnableTargetFollowing((int)secondary);
    GameResources* resources=GameResources_GetInstance();
    if(resources) GameResources_ClearSecondaryFlags((int)resources,0x80);
   }
  }
 }
 GameResources* resources=GameResources_GetInstance();
 if(resources) Resource_PollNestedLoaderIfPresent(resources);
 Handlers handlers=GameStateUpdateTimedStateHandlers_UnknownRoleProcedureReferenceRecords;
 int (*handler)(unsigned char*)=handlers.functions[*(int*)(self+8)];
 if(handler) *(int*)(self+8)=handler(self);
 if(LinkedList_ContainsNodeByIdentity(list,*(E**)((unsigned char*)resources+0x370c))) {
  self[1]=1;
  Memory_DestroyTwoAllocatorsAndRestoreGameFlags(self);
 }
 if(self[1]) GameResources_ClearSecondaryFlags((int)resources,0x40);
}
