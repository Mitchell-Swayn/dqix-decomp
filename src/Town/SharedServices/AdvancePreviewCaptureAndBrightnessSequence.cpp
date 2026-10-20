#include <globaldefs.h>
ARM
class GameResources;
extern "C" {
GameResources* GameResources_GetInstance();
void _ZN13SafeAllocator5ResetEv(void*);void _ZN8Object3D10InitializeEv(void*);void _ZN8Object3D11MakeVisibleEv(void*);
void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int);void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
int _Z32IsMainBrightnessTransitionActiveP13GameResources(void*);int _Z31IsSubBrightnessTransitionActiveP13GameResources(void*);int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
void ResourceHandle_InvokeOperationWithValidHalfwordIndex(char*,int,int,int);
void Bgm_RequestTemporarySequence(int,unsigned short);
void G3X_SetClearColor(unsigned,unsigned,unsigned short,unsigned,int);
void Town_LoadPreviewModel(unsigned char*);
void Graphics_LoadCanvasResourceBlocks(char*,int,int);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant2[];
}
// Original: arm9/ov003 @ 0x0217C2BC; symbol: func_ov003_0217c2bc; size: 0x490.
// Sequences preview visibility, capture modes and main/sub brightness transitions with frame countdowns.
extern "C" void AdvancePreviewCaptureAndBrightnessSequence(char* p) {
 GameResources* resources=GameResources_GetInstance();int phase=p[0x141];
 if(phase==0){p[0x142]=75;++p[0x141];}
 else if(phase==1){
 if(--((unsigned char*)p)[0x142])return;
 ((void(*)(char*,int,int))ResourceHandle_InvokeOperationWithValidHalfwordIndex)(Main_UnknownRoleZeroInitializedStorage,0,0);
 Graphics_LoadCanvasResourceBlocks(p,1,0);_ZN8Object3D11MakeVisibleEv(p+0x80);
 G3X_SetClearColor(0,0,0x7fff,0,0);
 *(volatile unsigned*)0x4000000=(*(volatile unsigned*)0x4000000&~0x1f00)|0x300;
 _Z13SetBrightnessP13GameResourcesii(resources,16,10);++p[0x141];
 }
 else if(phase==2){if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;_Z13SetBrightnessP13GameResourcesii(resources,7,20);++p[0x141];}
 else if(phase==3){if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;_Z13SetBrightnessP13GameResourcesii(resources,16,15);++p[0x141];}
 else if(phase==4){if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;_Z13SetBrightnessP13GameResourcesii(resources,-16,70);p[0x142]=60;++p[0x141];}
 else if(phase==5){if(--((unsigned char*)p)[0x142])return;_Z13SetBrightnessP13GameResourcesii(resources,16,7);++p[0x141];}
 else if(phase==6){if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;_Z13SetBrightnessP13GameResourcesii(resources,-16,30);++p[0x141];}
 else if(phase==7){
 if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;
 G3X_SetClearColor(0,31,0x7fff,0,0);
 *(volatile unsigned*)0x4000000=(*(volatile unsigned*)0x4000000&~0x1f00)|0x100;
 _ZN13SafeAllocator5ResetEv(p+4);_ZN8Object3D10InitializeEv(p+0x80);
 Town_LoadPreviewModel((unsigned char*)p);p[0x142]=60;++p[0x141];
 }
 else if(phase==8){if(--((unsigned char*)p)[0x142])return;Graphics_LoadCanvasResourceBlocks(p,0,0);_Z17SetMainBrightnessP13GameResourcesii(resources,0,90);p[0x142]=40;++p[0x141];}
 else if(phase==9){if(--((unsigned char*)p)[0x142])return;_Z16SetSubBrightnessP13GameResourcesii(resources,0,2);++p[0x141];}
 else if(phase==10){if(_Z31IsSubBrightnessTransitionActiveP13GameResources(resources))return;_Z16SetSubBrightnessP13GameResourcesii(resources,-16,5);++p[0x141];}
 else if(phase==11){if(_Z32IsMainBrightnessTransitionActiveP13GameResources(resources))return;_Z13SetBrightnessP13GameResourcesii(resources,16,10);++p[0x141];}
 else if(phase==12){if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;
 Bgm_RequestTemporarySequence((int)Main_UnknownRoleZeroInitializedStorage_Variant2,0x43);
 _Z13SetBrightnessP13GameResourcesii(resources,0,60);Graphics_LoadCanvasResourceBlocks(p,0,1);++p[0x141];}
 else if(phase==13){if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;p[0x142]=15;++p[0x141];}
 else if(phase==14){if(--((unsigned char*)p)[0x142])return;_Z13SetBrightnessP13GameResourcesii(resources,16,10);++p[0x141];}
 else if(phase==15){if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;_Z13SetBrightnessP13GameResourcesii(resources,0,30);++p[0x141];}
 else if(phase==16){if(!_Z28IsBrightnessTransitionActiveP13GameResources(resources)){p[0x140]=3;p[0x141]=0;}}
}
