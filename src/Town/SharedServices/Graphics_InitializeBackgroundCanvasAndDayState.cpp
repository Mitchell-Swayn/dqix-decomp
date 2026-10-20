#include <globaldefs.h>
ARM
extern "C" void Graphics_CacheFourMainBackgroundControlsOnce(void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void ResourceStringLoader_Reset(char*);
extern "C" void Selection_InitializeDisplayController(void*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
extern "C" void Graphics_InitializeSpriteResourceBuffers(unsigned char*);
extern "C" void _Z16GetDayThresholdsPfS_S_S_S_(float*,float*,float*,float*,float*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" bool _ZNK9GameState21IsMorningDayOrEveningEv(void*);
// Original: arm9/ov003 @ 0x0215C650; symbol: func_ov003_0215c650; size: 0x1B0.
extern "C" void Graphics_InitializeBackgroundCanvasAndDayState(unsigned char* self) {
 self[0x90]=0;self[0x91]=0;
 Graphics_CacheFourMainBackgroundControlsOnce(self+0x80);
 *(unsigned*)(self+0x94)=(*(volatile unsigned*)0x04000000&0x1f00)>>8;
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x100;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x28);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x3c);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x50);
 ResourceStringLoader_Reset((char*)self+0x64);
 *(int*)(self+0x7c)=0;
 Selection_InitializeDisplayController(self+0x98);
 for(int i=0;i<2;i++)Graphics_InitializeCanvasTransferState((char*)self+0x154+i*32);
 for(int i=0;i<2;i++)TextCanvas_InitializeLayoutAndTransferDefaults(self+0x194+i*224);
 *(int*)(self+0x354)=0;
 Graphics_InitializeSpriteResourceBuffers(self+0x358);
 *(int*)(self+0x3ac)=0;*(int*)(self+0x3b0)=0;*(int*)(self+0x3b4)=0;
 self[0x3b8]=0;self[0x3b9]=0;self[0x3bc]=0;self[0x3ba]=0;self[0x3bb]=0;
 for(int i=0;i<3;i++)(self+i)[0x3bd]=255;
 self[0x3c0]=0;((signed char*)self)[0x3c1]=-1;self[0x3c2]=0;self[0x3c3]=0;
 for(int i=0;i<4;i++)(self+i)[0x3c4]=255;
 *(int*)(self+0x3c8)=-1;*(int*)(self+0x3cc)=-1;
 _Z16GetDayThresholdsPfS_S_S_S_((float*)(self+0x3d4),(float*)(self+0x3d8),(float*)(self+0x3dc),(float*)(self+0x3e0),(float*)(self+0x3e4));
 *(int*)(self+0x3d0)=_ZNK9GameState21IsMorningDayOrEveningEv(_ZN9GameState11GetInstanceEv());
 self[0x3ec]=0;self[0x3ed]=0;self[0x3ee]=0;self[0x3ef]=1;
 self[0x3f0]=0;self[0x3f1]=0;self[0x3f2]=0;self[0x3f3]=0;
 *(int*)(self+0x3f8)=0;self[0x3f4]=0;self[0x3f5]=0;
 *(int*)(self+0x3e8)=0;
}
