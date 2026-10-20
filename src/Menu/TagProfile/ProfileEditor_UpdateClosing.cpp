#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" int _Z31IsSubBrightnessTransitionActiveP13GameResources(void*);
extern "C" void RestoreSubGraphicsBanksAndDestroyAllocators(void*);
extern "C" void Graphics_CopyContextTextForProtagonistAndSpecialMode(void*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_ClearFlags(void*,unsigned);
extern "C" void GameResources_ClearPrimaryFlags(void*,unsigned);
// Original: arm9/ov012 @ 0x02189264; symbol: Graphics_FadeSubScreenAndResetOwnerState; size: 0xa8.
extern "C" void ProfileEditor_UpdateClosing(char* self) {
 void* resources=GameResources_GetInstance();unsigned state=*(unsigned char*)(self+0x1370);
 if(state==0){_Z16SetSubBrightnessP13GameResourcesii(resources,-16,15);*(unsigned char*)(self+0x1370)+=1;return;}
 if(state!=1 || _Z31IsSubBrightnessTransitionActiveP13GameResources(resources))return;
 *(int*)(self+0x131c)=0;*(int*)(self+0x1324)=0;RestoreSubGraphicsBanksAndDestroyAllocators(self+0xd28);Graphics_CopyContextTextForProtagonistAndSpecialMode(self);SystemState_ClearFlags(SystemState_GetGlobalFlags(),15);GameResources_ClearPrimaryFlags(resources,16);*(int*)(self+0x139c)=1;*(unsigned char*)(self+0x1370)=0;
}
