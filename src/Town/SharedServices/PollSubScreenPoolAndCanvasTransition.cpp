#include <globaldefs.h>
ARM
class GameResources;struct Pool;
extern "C" {
GameResources* GameResources_GetInstance();void _ZN13SafeAllocator5ResetEv(void*);
void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);int _Z31IsSubBrightnessTransitionActiveP13GameResources(void*);
void SystemState_SetFlags(unsigned*,unsigned);void* SystemState_GetGlobalFlags();
void Tavern_UpdateStoredCharacterPreview(void*);void Memory_AllocateThreeSizedPools(Pool*,unsigned);
void CharacterStatus_InitializeSubDisplaySnapshot(void*,int,int);int PollSubCanvasAndTextResourceInitialization(char*);
}
// Original: arm9/ov003 @ 0x02160CF8; symbol: func_ov003_02160cf8; size: 0x13C.
// Fades sub-screen brightness around pool and canvas initialization; reports completion after clearing flag400.
extern "C" int PollSubScreenPoolAndCanvasTransition(char* p) {
 GameResources* resources=GameResources_GetInstance();void* global=SystemState_GetGlobalFlags();
 int done=0;unsigned phase=((unsigned char*)p)[0x4a8];
 if(phase==0){_Z16SetSubBrightnessP13GameResourcesii(resources,-16,8);++((unsigned char*)p)[0x4a8];}
 else if(phase==1){if(!_Z31IsSubBrightnessTransitionActiveP13GameResources(resources)){
 SystemState_SetFlags((unsigned*)global,1);_ZN13SafeAllocator5ResetEv(p+0x23c);
 CharacterStatus_InitializeSubDisplaySnapshot(*(void**)(p+0x318),0,-1);**(int**)(p+0x318)=*(int*)(p+0x398);
 Memory_AllocateThreeSizedPools(*(Pool**)(p+0x318),(unsigned)(p+0x23c));++((unsigned char*)p)[0x4a8];}}
 else if(phase==2){if(PollSubCanvasAndTextResourceInitialization(*(char**)(p+0x318))){Tavern_UpdateStoredCharacterPreview(p);++((unsigned char*)p)[0x4a8];}}
 else if(phase==3){_Z16SetSubBrightnessP13GameResourcesii(resources,0,8);++((unsigned char*)p)[0x4a8];}
 else if(phase==4){if(!_Z31IsSubBrightnessTransitionActiveP13GameResources(resources)){p[0x4a8]=0;*(unsigned*)(p+0x464)&=~0x400;done=1;}}
 return done;
}
