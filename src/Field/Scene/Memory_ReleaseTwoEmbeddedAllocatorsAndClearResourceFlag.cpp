#include <globaldefs.h>
ARM
struct GameResources; struct GameState;
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
extern "C" void* GameState_GetFieldOrbitCamera(GameState*);
extern "C" void Camera_EnableOrbitInput(void*);
extern "C" void GameResources_ClearSecondaryFlags(int,unsigned);
// Original: arm9/ov017 @ 0x021BF490; symbol: func_ov017_021bf490; size: 0xA4.
extern "C" void Memory_ReleaseTwoEmbeddedAllocatorsAndClearResourceFlag(unsigned char* self) {
 GameResources* resources=GameResources_GetInstance();
 if(self[0x48] && resources) { World_UpdateAndSnapshotObjectState(resources); self[0x48]=0; }
 void* storage=_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0x34);
 if(storage) { _ZN13SafeAllocator7DestroyEv(self+0x34); Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,storage); }
 storage=_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0x4c);
 if(storage) { _ZN13SafeAllocator7DestroyEv(self+0x4c); Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,storage); }
 void* object=GameState_GetFieldOrbitCamera((GameState*)_ZN9GameState11GetInstanceEv());
 if(object) Camera_EnableOrbitInput(object);
 if(resources) GameResources_ClearSecondaryFlags((int)resources,0x80);
}
