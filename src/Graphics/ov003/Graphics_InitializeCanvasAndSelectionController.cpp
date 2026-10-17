#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
extern "C" void InitializeRecordBuffersAndEnabledByte(unsigned char*);
extern "C" void InitializeRecordGridAndFlagDefaults(void*);
extern "C" void Graphics_CacheFourMainBackgroundControlsOnce(volatile void*);
extern "C" void ClearTwoBytesAndWord4(unsigned char*);
extern "C" void ClearRecordAndInvalidateTwoIndices(char*);
// Original: arm9/ov003 @ 0x02158BB8; symbol: func_ov003_02158bb8; size: 0x194.
extern "C" void Graphics_InitializeCanvasAndSelectionController(unsigned char* p) {
 p[0x90]=0;p[0x91]=0;
 Graphics_CacheFourMainBackgroundControlsOnce(p+0x80);
 volatile unsigned* display=(volatile unsigned*)0x4000000;
 *(unsigned*)(p+0x94)=(*display&0x1f00)>>8;
 *display=(*display&~0x1f00)|0x100;
 InitializeRecordBuffersAndEnabledByte(p+0x98);
 *(unsigned*)(p+0xec)=0;*(unsigned*)(p+0xf0)=0;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x3c);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x28);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x14);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p);
 InitializeRecordGridAndFlagDefaults(p+0xf4);
 for(int i=0;i<2;i++) Graphics_InitializeCanvasTransferState((char*)p+0x1b0+i*32);
 for(int i=0;i<4;i++) TextCanvas_InitializeLayoutAndTransferDefaults(p+0x1f0+i*0xe0);
 ClearRecordAndInvalidateTwoIndices((char*)p+0x64);
 p[0x587]=0;p[0x588]=0;p[0x580]=0;p[0x581]=0;p[0x589]=0;
 for(int i=0;i<6;i++) *(signed char*)(p+i+0x58a)=-1;
 p[0x590]=0;
 for(int i=0;i<4;i++) *(p+i+0x591)=255;
 p[0x584]=0;*(signed char*)(p+0x585)=-1;p[0x586]=0;*(signed char*)(p+0x5a1)=-1;
 *(unsigned*)(p+0x5a4)=0;*(unsigned*)(p+0x5a8)=0;*(unsigned*)(p+0x5ac)=0;
 p[0x59c]=0;p[0x582]=0;p[0x583]=0;p[0x59d]=0;p[0x59e]=0;
 *(unsigned*)(p+0x570)=0;
 p[0x59f]=0;p[0x5a0]=0;p[0x5b0]=0;p[0x5b1]=0;p[0x5b2]=1;p[0x5b3]=0;p[0x5b4]=0;
 ClearTwoBytesAndWord4(p+0x5b8);
 *(unsigned*)(p+0x598)=0;
}
