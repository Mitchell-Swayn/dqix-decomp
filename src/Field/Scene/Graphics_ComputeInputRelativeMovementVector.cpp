#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" char* GameState_ReadUnknownB0(void*);
extern "C" int Input_TestKeyMask(unsigned short*,unsigned short);
extern "C" void TouchMovement_GetDirectionVector(char*,int*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov017 @ 0x0218D8CC; symbol: func_ov017_0218d8cc; size: 0x17C.
extern "C" void Graphics_ComputeInputRelativeMovementVector(char* self) {
 void* state=_ZN9GameState11GetInstanceEv();
 char* object=_ZN9GameState20GetUnknownGameObjectEv(state);
 char* origin=GameState_ReadUnknownB0(state);
 if(!object || !origin)return;
 Vector3fix delta;
 Vector3fix_Subtract((Vector3fix*)(object+0x44),(Vector3fix*)(origin+4),&delta);
 Vector3fix forward;forward.x=delta.x;forward.y=0;forward.z=delta.z;
 Vector3fix back;back.x=-delta.x;back.y=0;back.z=-delta.z;
 Vector3fix left;left.x=delta.z;left.y=0;left.z=-delta.x;
 Vector3fix right;right.x=-delta.z;right.y=0;right.z=delta.x;
 *(int*)(self+0x4438)=0;*(int*)(self+0x443c)=0;*(int*)(self+0x4440)=0;
 if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x40))Vector3fix_Add((Vector3fix*)(self+0x4438),&forward,(Vector3fix*)(self+0x4438));
 else if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x80))Vector3fix_Add((Vector3fix*)(self+0x4438),&back,(Vector3fix*)(self+0x4438));
 if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x20))Vector3fix_Add((Vector3fix*)(self+0x4438),&left,(Vector3fix*)(self+0x4438));
 else if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x10))Vector3fix_Add((Vector3fix*)(self+0x4438),&right,(Vector3fix*)(self+0x4438));
 char* controller=*(char**)(self+0x4328);
 if(*(unsigned char*)(controller+0x224))TouchMovement_GetDirectionVector(controller,(int*)(self+0x4438));
 Vector3fix_Normalize((Vector3fix*)(self+0x4438),(Vector3fix*)(self+0x4438));
}
