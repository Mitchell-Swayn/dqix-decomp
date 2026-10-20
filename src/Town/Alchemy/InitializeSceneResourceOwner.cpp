#include <globaldefs.h>
ARM
extern "C" {
void* memset(void*,int,unsigned);
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
void _ZN8Object3D10InitializeEv(void*);
void Graphics_InitializeSpriteResourceBuffers(unsigned char*);
void ResourceLoader_InitializePresentationOwner(unsigned char*);
void KrakPot_InitializeItemPreviewSprite(unsigned char*);
void Resource_InitializeSharedRecordState(char*,unsigned short,int);
}
// Original: arm9/ov006 @ 0x02154614; symbol: func_ov006_02154614; size: 0x188.
// Clears scene resource ownership and initializes embedded models and allocators.
extern "C" void InitializeSceneResourceOwner(unsigned char* self) {
 memset(self,0,0x180);
 *(unsigned*)(self+384)=0;
 *(unsigned*)(self+388)=0;
 *(unsigned*)(self+392)=0;
 *(unsigned*)(self+416)=0;
 *(unsigned*)(self+424)=0;
 *(unsigned*)(self+428)=0;
 *(unsigned*)(self+432)=0;
 *(unsigned*)(self+436)=0;
 *(unsigned*)(self+440)=0;
 *(unsigned*)(self+444)=0;
 *(unsigned*)(self+448)=0;
 *(unsigned*)(self+452)=0;
 *(unsigned*)(self+456)=0;
 *(unsigned*)(self+460)=0;
 *(unsigned*)(self+464)=0;
 *(unsigned*)(self+468)=0;
 *(unsigned*)(self+472)=0;
 *(unsigned*)(self+476)=0;
 *(unsigned*)(self+480)=0;
 *(unsigned*)(self+4740)=0;
 *(unsigned*)(self+4736)=0;
 ((void(*)(char*,int,int))Resource_InitializeSharedRecordState)((char*)self+0xae4,-1,1);
 *(unsigned short*)(self+0x1258)|=0x210;
 Graphics_InitializeSpriteResourceBuffers(self+0x1e4);
 _ZN8Object3D10InitializeEv(self+568);
 _ZN8Object3D10InitializeEv(self+740);
 _ZN8Object3D10InitializeEv(self+912);
 _ZN8Object3D10InitializeEv(self+1084);
 _ZN8Object3D10InitializeEv(self+1256);
 memset(self+0x594,0,0x38);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x18c);
 for(unsigned char i=0;i<4;++i) {
  KrakPot_InitializeItemPreviewSprite(self+0x894+i*0x7c);
  _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0xa84+i*0x14);
 }
 *(int*)(self+0xad4)=-1;*(int*)(self+0xad8)=-1;
 self[0xadc]=0;self[0xadd]=0;self[0xade]=0;self[0xadf]=0;self[0xae0]=0;
 *(unsigned short*)(self+0xae2)=0;
 self[0x12bb]=0;*(short*)(self+0x12b8)=0;self[0x12ba]=0;self[0x12bc]=0;
 ResourceLoader_InitializePresentationOwner(self+0x12a0);
 self[0x12bd]=0;
}
