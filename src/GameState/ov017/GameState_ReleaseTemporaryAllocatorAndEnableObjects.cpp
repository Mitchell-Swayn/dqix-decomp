#include <globaldefs.h>
ARM
struct GameResources; struct GameState; struct MapGameObject;
extern "C" unsigned char data_02114e20[];
extern "C" GameResources* GameResources_GetInstance();
extern "C" void World_UpdateAndSnapshotObjectState(GameResources*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* GameState_GetField3B0ObjectWithFlag4(GameState*);
extern "C" void SetByteFieldAtOffset253ToOne(void*);
extern "C" void SetField238Enabled(void*);
extern "C" void ClearWordAtOffset4MaskedBits(int,unsigned);
// Original: arm9/ov017 @ 0x021AE760; symbol: func_ov017_021ae760; size: 0xA0.
extern "C" void GameState_ReleaseTemporaryAllocatorAndEnableObjects(unsigned char* self) {
 GameResources* resources=GameResources_GetInstance();
 self[1]=1;
 if(self[11] && resources) {
  World_UpdateAndSnapshotObjectState(resources);
  void* storage=_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0x2c);
  if(storage) { _ZN13SafeAllocator7DestroyEv(self+0x2c); Memory_FreeThroughAllocatorUnion(data_02114e20,storage); }
  self[11]=0;
 }
 void* state=_ZN9GameState11GetInstanceEv();
 void* object=_ZN9GameState20GetUnknownGameObjectEv(state);
 if(object) SetByteFieldAtOffset253ToOne(object);
 object=GameState_GetField3B0ObjectWithFlag4((GameState*)state);
 if(object) SetField238Enabled(object);
 if(resources) ClearWordAtOffset4MaskedBits((int)resources,0x80);
}
