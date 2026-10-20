#include <globaldefs.h>
ARM
struct State;
extern "C" {
void Graphics_CacheFourMainBackgroundControlsOnce(volatile State*);void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
void Selection_InitializeDisplayController(State*);void Graphics_InitializeCanvasTransferState(char*);void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);void Graphics_InitializeSpriteResourceBuffers(unsigned char*);void ResourceStringLoader_Reset(char*);void Menu_ResetLayout(char*);void Bank_ResetDigitTouchRepeat(int);
}
// Original: arm9/ov003 @ 0x021681C8; symbol: func_ov003_021681c8; size: 0x15C.
// Saves the main background controls and initializes embedded transfer dialog records.
extern "C" void InitializeTransferDialogAndSaveBackgroundState(unsigned char* p){
 p[0xdc]=0;p[0xdd]=0;Graphics_CacheFourMainBackgroundControlsOnce((State*)(p+0xcc));
 *(unsigned*)(p+0xe0)=(*(volatile unsigned*)0x4000000&0x1f00)>>8;*(volatile unsigned*)0x4000000=(*(volatile unsigned*)0x4000000&~0x1f00)|0x100;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x50);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x3c);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x28);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x14);_ZN13SafeAllocator21ResetAllocatorPointerEv(p);
 Selection_InitializeDisplayController((State*)(p+0xe4));
 for(int i=0;i<2;++i)Graphics_InitializeCanvasTransferState((char*)p+0x1a0+i*32);
 for(int i=0;i<3;++i)TextCanvas_InitializeLayoutAndTransferDefaults(p+0x1e0+i*224);
 Graphics_InitializeSpriteResourceBuffers(p+0x480);*(int*)(p+0x4d4)=0;*(int*)(p+0x4d8)=0;ResourceStringLoader_Reset((char*)p+0x64);Menu_ResetLayout((char*)p+0x80);
 *(int*)(p+0x4dc)=0;p[0x4ec]=0;p[0x4e8]=0;p[0x4e9]=0;p[0x4ea]=0;p[0x4eb]=0;p[0x4ed]=0;p[0x4ee]=0;
 for(int i=0;i<4;++i)(p+i)[0x4ef]=0;
 for(int i=0;i<4;++i)(p+i)[0x4f3]=0;
 *(int*)(p+0x4f8)=0;*(int*)(p+0x5a0)=0;p[0x5a4]=0;p[0x5a5]=0;p[0x59f]=0;Bank_ResetDigitTouchRepeat((int)p);
}
