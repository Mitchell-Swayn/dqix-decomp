#include <globaldefs.h>
ARM
struct Object; struct GameResources;
extern "C" void* memset(void*,int,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameResources_GetInstance();
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_ClearFlags(unsigned int*,unsigned int);
extern "C" void SpriteAnimation_ClearTrackList(unsigned int*);
extern "C" void Graphics_FinalizeSpriteResourceBuffers(void*);
extern "C" void Graphics_ClearSubBG1CharacterAndScreenBuffers();
extern "C" void Graphics_ApplyMainBackgroundSnapshotAndClearPending(Object*);
extern "C" void Graphics_ApplySubBackgroundSnapshotAndClearPending(Object*);
extern "C" void GameResources_ClearPrimaryFlags(unsigned int*,unsigned int);
extern "C" void GameResources_ClearSecondaryFlags(int,unsigned int);
extern "C" void ResetWordAndTwoHalfwordRecord(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);
extern "C" unsigned int GetMainBG1ScreenBase();
extern "C" unsigned long long _Z19GetCurrentTimestampv();
// Original: arm9/ov003 @ 0x02173D40; symbol: func_ov003_02173d40; size: 0x168.
extern "C" void Graphics_ResetInterfaceBuffersAndState(unsigned char* self) {
 unsigned char* game=(unsigned char*)_ZN9GameState11GetInstanceEv();
 GameResources* resources=GameResources_GetInstance();
 unsigned char* global=(unsigned char*)TextContext_GetSharedInstance();
 SystemState_ClearFlags((unsigned int*)SystemState_GetGlobalFlags(),0x1000);
 global[0x19be]=0;
 SpriteAnimation_ClearTrackList(*(unsigned int**)(self+0x12c));
 Graphics_FinalizeSpriteResourceBuffers(self+0x130);
 ((void(*)(void*))Graphics_ClearSubBG1CharacterAndScreenBuffers)(self+0xd8);
 *(volatile unsigned int*)0x04001010=0;
 Graphics_ApplyMainBackgroundSnapshotAndClearPending((Object*)(self+0xfa));
 Graphics_ApplySubBackgroundSnapshotAndClearPending((Object*)(self+0x10c));
 *(volatile unsigned int*)0x04000000=(*(volatile unsigned int*)0x04000000&~0x1f00)|(*(unsigned int*)(self+0x120)<<8);
 *(volatile unsigned int*)0x04001000=(*(volatile unsigned int*)0x04001000&~0x1f00)|(*(unsigned int*)(self+0x124)<<8);
 GameResources_ClearPrimaryFlags((unsigned int*)resources,4);
 GameResources_ClearSecondaryFlags((int)resources,0x81e);
 ResetWordAndTwoHalfwordRecord(self+0x1c8);
 ResetWordAndTwoHalfwordRecord(self+0x1d0);
 ResetWordAndTwoHalfwordRecord(self+0x1d8);
 _ZN13SafeAllocator7DestroyEv(self+0x184);
 _ZN13SafeAllocator7DestroyEv(self+0x198);
 _ZN13SafeAllocator7DestroyEv(self+0x1ac);
 unsigned char zero[32];
 memset(zero,0,32);
 _Z15CleanCacheRangePKvj(zero,32);
 _Z25CleanInvalidateCacheRangePKvj(zero,32);
 LoadToMainBG1CharacterData(zero,0,32);
 memset((void*)GetMainBG1ScreenBase(),0,0x800);
 *(int*)(global+0x2d8)=0;
 *(int*)(global+0x2dc)=0;
 *(int*)(global+0x2e0)=0;
 *(unsigned long long*)(game+0x3e8)=_Z19GetCurrentTimestampv();
 *(unsigned long long*)(game+0x3f0)=_Z19GetCurrentTimestampv();
}
