#include <globaldefs.h>
ARM
struct Object;struct GameState;struct GameResources;struct MapGameObject;struct E;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void Object_ClearTwoStateFieldsAndOptionallyResetAnimation(Object*,int);
extern "C" void* GameState_GetField3B0ObjectWithFlag4(GameState*);
extern "C" void ClearWordFieldAtOffset238(int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void Object_SetUnsignedIntAtOffset4(int,unsigned);
extern "C" void SetByteFieldAtOffset253ToOne(int);
extern "C" void SetField238Enabled(int);
extern "C" void ClearWordAtOffset4MaskedBits(int,unsigned);
extern "C" void Resource_PollNestedLoaderIfPresent(void*);
extern "C" int LinkedList_ContainsNodeByIdentity(E**,E*);
extern "C" void Memory_DestroyTwoAllocatorsAndRestoreGameFlags(void*);
struct Handlers {int (*functions[7])(unsigned char*);};
extern "C" Handlers data_ov017_021d6c04;
// Original: arm9/ov017 @ 0x021B58B8; symbol: func_ov017_021b58b8; size: 0x16C.
extern "C" void GameState_UpdateTimedStateHandlers(unsigned char* self,E** list) {
 if(*(unsigned short*)(self+0x18)) {
  void* game=_ZN9GameState11GetInstanceEv();
  unsigned char* object=(unsigned char*)_ZN9GameState20GetUnknownGameObjectEv(game);
  if(object) {
   unsigned elapsed=_ZNK9GameState21GetEffectiveDeltaTimeEv(game);
   if(elapsed<*(unsigned short*)(self+0x18)) {
    Object_ClearTwoStateFieldsAndOptionallyResetAnimation((Object*)object,1);
    *(short*)(object+0xb2)=0;
    *(unsigned short*)(self+0x18)-=elapsed;
    void* secondary=GameState_GetField3B0ObjectWithFlag4((GameState*)game);
    if(secondary) ClearWordFieldAtOffset238((int)secondary);
    GameResources* resources=GameResources_GetInstance();
    if(resources) Object_SetUnsignedIntAtOffset4((int)resources,0x80);
   } else if(!self[0x54]) {
    SetByteFieldAtOffset253ToOne((int)object);
    *(unsigned short*)(self+0x18)=0;
    void* secondary=GameState_GetField3B0ObjectWithFlag4((GameState*)game);
    if(secondary) SetField238Enabled((int)secondary);
    GameResources* resources=GameResources_GetInstance();
    if(resources) ClearWordAtOffset4MaskedBits((int)resources,0x80);
   }
  }
 }
 GameResources* resources=GameResources_GetInstance();
 if(resources) Resource_PollNestedLoaderIfPresent(resources);
 Handlers handlers=data_ov017_021d6c04;
 int (*handler)(unsigned char*)=handlers.functions[*(int*)(self+8)];
 if(handler) *(int*)(self+8)=handler(self);
 if(LinkedList_ContainsNodeByIdentity(list,*(E**)((unsigned char*)resources+0x370c))) {
  self[1]=1;
  Memory_DestroyTwoAllocatorsAndRestoreGameFlags(self);
 }
 if(self[1]) ClearWordAtOffset4MaskedBits((int)resources,0x40);
}
