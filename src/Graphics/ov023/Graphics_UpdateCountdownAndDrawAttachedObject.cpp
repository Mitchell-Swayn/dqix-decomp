#include <globaldefs.h>
ARM
struct GameResources;
extern "C" {void* _ZN9GameState11GetInstanceEv();GameResources* GameResources_GetInstance();unsigned ReadWordAtOverlayOffset4340(void*);void* ReadPointerField433C(void*);void Graphics_DrawObjectWithBoneAttachments(unsigned char*,void**);}
// Original: arm9/ov023 @ 0x021E3084; symbol: func_ov023_021e3084; size: 0xB0.
extern "C" void Graphics_UpdateCountdownAndDrawAttachedObject(unsigned char* p){
_ZN9GameState11GetInstanceEv();
if(*(int*)(p+0x134)>0){--*(int*)(p+0x134);if(*(int*)(p+0x134)==0)*(unsigned short*)(p+0x634)|=8;}
if(*(unsigned short*)(p+0x634)&0x20){
GameResources* resources=GameResources_GetInstance();void* attached[2];
if(!resources){attached[1]=0;attached[0]=0;}
else{attached[1]=(void*)ReadWordAtOverlayOffset4340(resources);attached[0]=ReadPointerField433C(resources);}
if(*(unsigned char**)(p+0x128)){
*(volatile unsigned*)0x04000444=0;
Graphics_DrawObjectWithBoneAttachments(*(unsigned char**)(p+0x128),attached);
*(volatile unsigned*)0x04000448=1;
}
}
}
