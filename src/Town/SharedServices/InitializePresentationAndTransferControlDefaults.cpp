#include <globaldefs.h>
ARM
extern "C" {
void* memset(void*,int,unsigned);void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);void _ZN8Object3D10InitializeEv(void*);
void Graphics_InitializeSpriteResourceBuffers(unsigned char*);void SaveData_ResetTransferProgress(unsigned char*);void ResourceStringLoader_Reset(char*);
void Graphics_InitializeBackgroundCanvasAndDayState(unsigned char*);void GuestList_InitializePresentation(unsigned char*);void TagMode_InitializeExchangeState(void*);
}
// Original: arm9/ov003 @ 0x0216D63C; symbol: func_ov003_0216d63c; size: 0x140.
// Saves display enable bits and initializes embedded presentation, allocators, preview and transfer control fields.
extern "C" void InitializePresentationAndTransferControlDefaults(char* p) {
 *(unsigned*)p=(*(volatile unsigned*)0x4000000&0x1f00)>>8;
 *(short*)(p+4)=0;*(short*)(p+6)=0;*(short*)(p+8)=0;p[0x13ec]=0;*(short*)(p+10)=0;*(int*)(p+12)=0;*(int*)(p+16)=0;
 Graphics_InitializeBackgroundCanvasAndDayState((unsigned char*)p+0x14);GuestList_InitializePresentation((unsigned char*)p+0x410);TagMode_InitializeExchangeState(p+0x7e0);
 *(char**)(p+0xf08)=p+0x410;*(int*)(p+0x1264)=0;*(int*)(p+0x1268)=0;Graphics_InitializeSpriteResourceBuffers((unsigned char*)p+0x126c);
 *(int*)(p+0x12c0)=0;*(int*)(p+0x12c4)=0;*(int*)(p+0x12c8)=0;*(int*)(p+0x12cc)=0;*(int*)(p+0x12d0)=0;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x12d4);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x12e8);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x12fc);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x1310);
 ResourceStringLoader_Reset(p+0x1324);_ZN8Object3D10InitializeEv(p+0x133c);
 p[0x13e8]=0;p[0x13e9]=0;p[0x13ea]=0;p[0x13eb]=1;p[0x13ef]=0;*(int*)(p+0x13f0)=0;p[0x13ee]=0;*(int*)(p+0x13f4)=-1;
 memset(p+0x13fc,-1,3);*(int*)(p+0x1408)=0;p[0x13ed]=0;SaveData_ResetTransferProgress((unsigned char*)p+0x140c);
}
