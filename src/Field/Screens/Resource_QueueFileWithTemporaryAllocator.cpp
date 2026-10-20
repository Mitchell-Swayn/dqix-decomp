#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameResources_GetInstance();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" unsigned char* GameState_GetFieldOrbitCamera(void*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned GameResources_GetSecondaryFlags(void*);
extern "C" void GameObject_DisableMovementInput(void*,int);
extern "C" void Camera_SetFollowControlFlags(int,unsigned char);
extern "C" void Camera_DisableOrbitInput(void*);
extern "C" bool LinkedQueue_IsEmpty(const int*);
extern "C" void GameResources_SetPrimaryFlags(unsigned*,unsigned);
extern "C" int Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned);
extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
extern "C" void DisableInterruptsAndHaltForever();
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" void* Script_ReadGlobalExecutionValue();
extern "C" void TimedMessageQueue_CancelAndClear(void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" const char Resource_QueueFileWithTemporaryAllocator_PathDataMenuS[];
struct LoadFlags { unsigned unused:4; unsigned skipBrightness:1; unsigned rest:27; };
// Original: arm9/ov017 @ 0x021B2388; symbol: func_ov017_021b2388; size: 0x148.
extern "C" int Resource_QueueFileWithTemporaryAllocator(unsigned char* p) {
 char path[80];
 void* state=_ZN9GameState11GetInstanceEv();
 char* resources=GameResources_GetInstance();
 void* object=_ZN9GameState20GetUnknownGameObjectEv(state);
 unsigned char* other=GameState_GetFieldOrbitCamera(state);
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 const int* ready=*(int**)(resources+0x3700);
 *(unsigned*)(p+0x40)=GameResources_GetSecondaryFlags(resources);
 if(object) GameObject_DisableMovementInput(object,1);
 if(other) {
  p[0x3e]=(other[0x244]&2)!=0;
  Camera_SetFollowControlFlags((int)other,2);
  Camera_DisableOrbitInput(other);
  *(void**)(p+0x44)=other;
 }
 if(!LinkedQueue_IsEmpty(ready)) return *(int*)(p+8);
 GameResources_SetPrimaryFlags((unsigned*)resources,16);
 Filesystem_FreeCachedTableIfAllocationNeedsSpace(0x2f800);
 void* buffer=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,0x2f800);
 if(!buffer) DisableInterruptsAndHaltForever();
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x10,buffer,0x2f800);
 sprintf(path,Resource_QueueFileWithTemporaryAllocator_PathDataMenuS,p+0x24);
 *(unsigned*)(p+12)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,p+0x10);
 if(!((LoadFlags*)(p+0x38))->skipBrightness) _Z13SetBrightnessP13GameResourcesii(resources,-16,30);
 TimedMessageQueue_CancelAndClear(Script_ReadGlobalExecutionValue());
 return 1;
}
