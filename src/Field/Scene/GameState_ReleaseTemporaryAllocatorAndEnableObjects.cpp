#include <globaldefs.h>
ARM
struct GameResources; struct GameState; struct MapGameObject;
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" GameResources* GameResources_GetInstance();
extern "C" void World_UpdateAndSnapshotObjectState(GameResources*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* GameState_GetFieldOrbitCamera(GameState*);
extern "C" void GameObject_RequestMovementInputEnable(void*);
extern "C" void Camera_EnableTargetFollowing(void*);
extern "C" void GameResources_ClearSecondaryFlags(int,unsigned);
// Original: arm9/ov017 @ 0x021AE760; symbol: func_ov017_021ae760; size: 0xA0.
extern "C" void GameState_ReleaseTemporaryAllocatorAndEnableObjects(unsigned char* self) {
 GameResources* resources=GameResources_GetInstance();
 self[1]=1;
 if(self[11] && resources) {
  World_UpdateAndSnapshotObjectState(resources);
  void* storage=_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0x2c);
  if(storage) { _ZN13SafeAllocator7DestroyEv(self+0x2c); Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,storage); }
  self[11]=0;
 }
 void* state=_ZN9GameState11GetInstanceEv();
 void* object=_ZN9GameState20GetUnknownGameObjectEv(state);
 if(object) GameObject_RequestMovementInputEnable(object);
 object=GameState_GetFieldOrbitCamera((GameState*)state);
 if(object) Camera_EnableTargetFollowing(object);
 if(resources) GameResources_ClearSecondaryFlags((int)resources,0x80);
}
