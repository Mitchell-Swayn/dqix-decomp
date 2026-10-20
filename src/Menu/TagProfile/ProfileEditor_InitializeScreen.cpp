#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct State;
extern "C" void Graphics_CacheFourMainBackgroundControlsOnce(volatile State*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void Graphics_InitializeSecondaryDisplayResourceContext(char*,int);
extern "C" void MessageTextTable_Reset(char*);
extern "C" void ResourceStringLoader_Reset(char*);
extern "C" void Selection_InitializeDisplayController(State*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
extern "C" void ProfileTextFilter_InitializeGlyphLookup(unsigned char*);
struct Counts { unsigned short flags:5; unsigned short count:11; };
// Original: arm9/ov012 @ 0x021843D4; symbol: func_ov012_021843d4; size: 0x224.
// Resets record-screen allocators, graphics controls, text canvases and selections.
extern "C" void ProfileEditor_InitializeScreen(char* p) {
 *(int*)(p)=0; *(int*)(p+4)=0; p[0x18]=0; p[0x19]=0;
 Graphics_CacheFourMainBackgroundControlsOnce((volatile State*)(p+8));
 *(unsigned*)(p+0x1c)=(*(volatile unsigned*)0x04000000 &0x1f00)>>8;
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000 &~0x1f00)|0x100;
 p[0x14bc]=0;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x20);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x34);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x48);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x5c);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x84);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x98);
 Graphics_InitializeSecondaryDisplayResourceContext(p+0xd28,2);
 MessageTextTable_Reset(p+0x133c);
 ResourceStringLoader_Reset(p+0x1344);
 *(int*)(p+0x135c)=0;
 *(int*)(p+0x1364)=0;
 *(int*)(p+0x1360)=0;
 *(int*)(p+0x1368)=0;
 *(int*)(p+0x136c)=0;
 Selection_InitializeDisplayController((State*)(p+0xac));
 for(int i=0;i<3;i++) Graphics_InitializeCanvasTransferState(p+0x168+i*32);
 for(int i=0;i<13;i++) TextCanvas_InitializeLayoutAndTransferDefaults((unsigned char*)p+0x1c8+i*224);
 *(char*)(p+0x1370)=0;
 *(char*)(p+0x1371)=0;
 *(int*)(p+0x1374)=0;
 *(int*)(p+0x137c)=0;
 *(int*)(p+0x1378)=0;
 *(int*)(p+0x139c)=0;
 *(char*)(p+0x13a0)=0;
 *(int*)(p+0x1398)=0;
 for(int i=0;i<6;i++) *(int*)(p+0x1380+i*4)=-1;
 p[0x13a8]=-1;
 p[0x13a9]=0;
 p[0x13aa]=0;
 p[0x13ab]=0;
 *(int*)(p+0x13ac)=0;
 *(int*)(p+0x13b0)=0;
 *(int*)(p+0x13b4)=0;
 *(int*)(p+0x13b8)=0;
 *(int*)(p+0x13bc)=0;
 *(int*)(p+0x13c0)=0;
 ((Counts*)(p+0x13c4))->flags=0;
 ((Counts*)(p+0x13c4))->count=0;
 *(int*)(p+0x13c8)=0;
 *(int*)(p+0x13cc)=0;
 *(int*)(p+0x13d0)=0;
 *(int*)(p+0x13d4)=0;
 *(int*)(p+0x13f4)=0;
 *(int*)(p+0x13f8)=0;
 *(short*)(p+0x13fc)=0; p[0x13fe]=0; p[0x13ff]=0;
 *(int*)(p+0x13d8)=-1;
 *(int*)(p+0x13dc)=-1;
 *(int*)(p+0x13e0)=-1;
 *(int*)(p+0x13e4)=-1;
 *(int*)(p+0x13e8)=-1;
 *(int*)(p+0x13ec)=-1;
 memset(p+0x1400,0,64);
 memset(p+0x1440,0,64);
 ProfileTextFilter_InitializeGlyphLookup((unsigned char*)p+0x1480);
 p[0x14bd]=0;
}
