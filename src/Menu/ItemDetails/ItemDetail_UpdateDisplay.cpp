#include <globaldefs.h>
ARM
extern "C" void Graphics_ConsumeReadyBackgroundResourceBlocks(void*);
extern "C" void ItemDetail_DrawIconsAndPreviewSprite(void*);
extern "C" void ItemDetail_DrawQuantityModeIcon(void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadPResources(void*);
extern "C" void Graphics_SetMainOrSubBrightness(void*,int,int);
// Original: arm9/ov023 @ 0x021DD974; symbol: Graphics_UpdateMemberAndConsumeBrightnessResetFlag; size: 0x90.
extern "C" void Resource_AdvanceMemberTaskStateMachine(char*);
extern "C" void ItemDetail_UpdateDisplay(char *self) {
 if(!(*(unsigned short*)(self+0x774)&0x4000))Resource_AdvanceMemberTaskStateMachine(self);
 Graphics_ConsumeReadyBackgroundResourceBlocks(self);
 if(*(signed char*)(self+0x77d)>=0){ItemDetail_DrawIconsAndPreviewSprite(self);ItemDetail_DrawQuantityModeIcon(self);}
 if(!(*(unsigned short*)(self+0x774)&64))return;
 GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
 if(!(*(unsigned short*)(self+0x774)&32))return;
 Graphics_SetMainOrSubBrightness(self,0,8);*(unsigned short*)(self+0x774)&=~32;
}
