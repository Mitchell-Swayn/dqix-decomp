#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameResources_GetInstance();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" unsigned char* GameState_GetField3B0ObjectWithFlag4(void*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned ReadWordFieldAtOffset4(void*);
extern "C" void Object_ClearTwoStateFieldsAndOptionallyResetAnimation(void*,int);
extern "C" void SetField244MaskedBits(int,unsigned char);
extern "C" void ClearWordAtOffset23C(void*);
extern "C" bool IsFirstSignedWordZero(const int*);
extern "C" void SetWordMaskBits_Main0203B4A0(unsigned*,unsigned);
extern "C" int Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned);
extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
extern "C" void DisableInterruptsAndHaltForever();
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" void* Script_ReadGlobalExecutionValue();
extern "C" void CleanupOptionalResourceAndResetStateOwner(void*);
extern "C" char data_02114e20[];
extern "C" const char data_ov017_021d7a28[];
struct LoadFlags { unsigned unused:4; unsigned skipBrightness:1; unsigned rest:27; };
// Original: arm9/ov017 @ 0x021B2388; symbol: func_ov017_021b2388; size: 0x148.
extern "C" int Resource_QueueFileWithTemporaryAllocator(unsigned char* p) {
 char path[80];
 void* state=_ZN9GameState11GetInstanceEv();
 char* resources=GameResources_GetInstance();
 void* object=_ZN9GameState20GetUnknownGameObjectEv(state);
 unsigned char* other=GameState_GetField3B0ObjectWithFlag4(state);
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 const int* ready=*(int**)(resources+0x3700);
 *(unsigned*)(p+0x40)=ReadWordFieldAtOffset4(resources);
 if(object) Object_ClearTwoStateFieldsAndOptionallyResetAnimation(object,1);
 if(other) {
  p[0x3e]=(other[0x244]&2)!=0;
  SetField244MaskedBits((int)other,2);
  ClearWordAtOffset23C(other);
  *(void**)(p+0x44)=other;
 }
 if(!IsFirstSignedWordZero(ready)) return *(int*)(p+8);
 SetWordMaskBits_Main0203B4A0((unsigned*)resources,16);
 Filesystem_FreeCachedTableIfAllocationNeedsSpace(0x2f800);
 void* buffer=AllocatorUnion_AllocateFourByteAligned(data_02114e20,0x2f800);
 if(!buffer) DisableInterruptsAndHaltForever();
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x10,buffer,0x2f800);
 sprintf(path,data_ov017_021d7a28,p+0x24);
 *(unsigned*)(p+12)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,p+0x10);
 if(!((LoadFlags*)(p+0x38))->skipBrightness) _Z13SetBrightnessP13GameResourcesii(resources,-16,30);
 CleanupOptionalResourceAndResetStateOwner(Script_ReadGlobalExecutionValue());
 return 1;
}
