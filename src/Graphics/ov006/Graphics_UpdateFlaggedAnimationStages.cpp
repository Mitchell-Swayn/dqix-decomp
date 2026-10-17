#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_ReadPResources(void*);
void Object_SetUnsignedIntAtOffset4(int,unsigned);
void ClearWordAtOffset4MaskedBits(int,unsigned);
void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void*,const char*,int);
void _ZN8Object3D10EnableFlagEi(void*,int);
void _ZN8Object3D11DisableFlagEi(void*,int);
void _ZN8Object3D20StopCurrentAnimationEv(void*);
int _ZNK8Object3D19HasAnimationStoppedEv(void*);
int _ZNK8Object3D22HasAnimationReachedEndEv(void*);
void UpdateObjectStateAndStoredValue(void*,unsigned,unsigned short);
void ResourceHandle_InvokeOperationWithValidHalfwordIndex(char*,int,int);
void DispatchStoredResourceHandleAtOffsetC0(unsigned char*);
extern char data_02108760[],data_ov006_02160080[],data_ov006_02160087[],data_ov006_02160089[],data_ov006_0216008b[],data_ov006_02160092[],data_ov006_02160094[],data_ov006_02160096[],data_ov006_0216009e[],data_ov006_021600a0[],data_ov006_021600a9[];
}
#define FLAGS (*(unsigned short*)(p+0xae2))
#define STAGE (*(unsigned char*)(p+0xae1))
#define ANIM(o,s,n) _ZN8Object3D24MaybeSetRegularAnimationEPKci(p+o,data_ov006_##s,n)
// Original: arm9/ov006 @ 0x02155068; symbol: func_ov006_02155068; size: 0x340.
extern "C" void Graphics_UpdateFlaggedAnimationStages(char* p){
void* resources=GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
if(FLAGS&0x2000){Object_SetUnsignedIntAtOffset4((int)resources,0x2000);ANIM(0x4e8,02160080,9);_ZN8Object3D10EnableFlagEi(p+0x4e8,0x1000);return;}
if(FLAGS&0x80){
 if(STAGE==0){UpdateObjectStateAndStoredValue(data_02108760,0x7a,0x7a);ResourceHandle_InvokeOperationWithValidHalfwordIndex(data_02108760,0,0);ANIM(0x2e4,02160080,1);ANIM(0x43c,02160087,1);ANIM(0x4e8,02160080,9);_ZN8Object3D11DisableFlagEi(p+0x4e8,0x1000);}
 else if(STAGE>=1){if(_ZNK8Object3D19HasAnimationStoppedEv(p+0x2e4)){STAGE=0;FLAGS&=~0x80;ANIM(0x43c,02160089,1);ANIM(0x2e4,0216008b,0);_ZN8Object3D20StopCurrentAnimationEv(p+0x4e8);return;}}
 STAGE++;return;
}
if(FLAGS&0x100){
 if(!_ZNK8Object3D22HasAnimationReachedEndEv(p+0x2e4))return;
 if(STAGE==0){ANIM(0x43c,02160092,0);}
 else if(STAGE==1){ANIM(0x43c,02160094,1);}
 else if(STAGE==2){STAGE=0;_ZN8Object3D20StopCurrentAnimationEv(p+0x2e4);ANIM(0x2e4,02160096,1);ANIM(0x43c,0216009e,0);ANIM(0x4e8,02160096,1);FLAGS&=~0x100;return;}
 STAGE++;return;
}
if(FLAGS&0x200){FLAGS|=0x800;if(!_ZNK8Object3D19HasAnimationStoppedEv(p+0x2e4)){STAGE++;return;}
 ClearWordAtOffset4MaskedBits((int)resources,0x2000);DispatchStoredResourceHandleAtOffsetC0((unsigned char*)data_02108760);STAGE=0;ANIM(0x2e4,021600a0,1);_ZN8Object3D20StopCurrentAnimationEv(p+0x43c);FLAGS&=~0x200;return;
}
if(FLAGS&0x400){if(_ZNK8Object3D19HasAnimationStoppedEv(p+0x2e4)){STAGE=0;ANIM(0x2e4,021600a9,0);_ZN8Object3D20StopCurrentAnimationEv(p+0x43c);FLAGS&=~0x400;return;}ANIM(0x2e4,021600a0,1);return;}
STAGE=0;ANIM(0x2e4,021600a9,0);_ZN8Object3D20StopCurrentAnimationEv(p+0x43c);
}
