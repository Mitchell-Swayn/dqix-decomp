#include <globaldefs.h>
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* GameState_ReadPResources(void*);extern "C" void* GameState_ReadUnknownB0(void*);extern "C" void Camera_SetRollAndStopTransition(void*,int);extern "C" void Camera_SetProjectionAngle(void*,int);extern "C" void Camera_RecalculateOrbitAndEye(void*);extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);extern "C" void _ZN13SafeAllocator5ResetEv(void*);extern "C" void _ZN13SafeAllocator7DestroyEv(void*);extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/main @ 0x02046F84; symbol: func_02046f84; size: 0x88.
extern "C" ARM void ModelObject_ReleaseOwnedArenaAndResetCamera(int* p){void* state=_ZN9GameState11GetInstanceEv();GameState_ReadPResources(state);void* obj=GameState_ReadUnknownB0(state);Camera_SetRollAndStopTransition(obj,0);Camera_SetProjectionAngle(obj,0xf000);Camera_RecalculateOrbitAndEye(obj);if(!p[14]){void* alloc=_ZNK13SafeAllocator18GetSignedAllocatorEv(p+9);if(alloc){_ZN13SafeAllocator5ResetEv(p+9);_ZN13SafeAllocator7DestroyEv(p+9);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,alloc);}}p[0]=0;p[1]=0;}
