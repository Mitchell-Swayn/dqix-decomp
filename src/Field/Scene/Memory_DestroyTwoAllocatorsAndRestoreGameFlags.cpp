#include <globaldefs.h>
ARM
struct GameResources;struct MapGameObject;struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* GameState_GetFieldOrbitCamera(GameState*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void GameObject_RequestMovementInputEnable(void*);
extern "C" void GameResources_ClearSecondaryFlags(int,unsigned);
extern "C" void Camera_EnableTargetFollowing(void*);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void World_UpdateAndSnapshotObjectState(GameResources*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov017 @ 0x021B5A30; symbol: func_ov017_021b5a30; size: 0xBC.
extern "C" void Memory_DestroyTwoAllocatorsAndRestoreGameFlags(unsigned char* p){
 GameResources* resources=GameResources_GetInstance();
 if(p[0x54] && resources){World_UpdateAndSnapshotObjectState(resources);p[0x54]=0;}
 void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x40);
 if(allocation){_ZN13SafeAllocator7DestroyEv(p+0x40);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);}
 allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x58);
 if(allocation){_ZN13SafeAllocator7DestroyEv(p+0x58);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);}
 void* gs=_ZN9GameState11GetInstanceEv();
 void* object=_ZN9GameState20GetUnknownGameObjectEv(gs);
 if(object)GameObject_RequestMovementInputEnable(object);
 object=GameState_GetFieldOrbitCamera((GameState*)gs);
 if(object)Camera_EnableTargetFollowing(object);
 if(resources)GameResources_ClearSecondaryFlags((int)resources,128);
}
