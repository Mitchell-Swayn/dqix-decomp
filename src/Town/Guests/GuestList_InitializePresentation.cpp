#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* memset(void*,int,unsigned);void Graphics_InitializeSpriteResourceBuffers(unsigned char*);void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);void ResourceStringLoader_Reset(void*);void TextLayout_InitializeSelectionPanel(unsigned char*);}
// Original: arm9/ov003 @ 0x0216FFBC; symbol: Resource_InitializeSelectionPresentationDefaults; size: 0x100.
// Initializes flags, invalid indices, text buffers, allocator and selection controls.
extern "C" void GuestList_InitializePresentation(unsigned char* self){self[0]=1;self[1]=0;self[2]=0;self[3]=0;self[4]=0;self[5]=0;self[6]=0;((signed char*)self)[7]=-1;self[8]=0;((signed char*)self)[9]=-1;self[10]=0;H(self,12)=0;H(self,14)=0;W(self,16)=-1;W(self,20)=0;W(self,24)=0;W(self,28)=-1;H(self,32)=0;W(self,36)=0;H(self,40)=0;for(int i=0;i<3;++i)H(self+i*2,0x2a)=-1;memset(self+0x30,0,11);self[0x3b]=0;W(self,0x3c)=0;W(self,0x40)=0;W(self,0x44)=0;self[0x58]=0;self[0x59]=0;W(self,0x5c)=0;W(self,0x60)=0;W(self,0x64)=0;Graphics_InitializeSpriteResourceBuffers(self+0x68);_ZN13SafeAllocator21ResetAllocatorPointerEv(self+0xbc);W(self,0xd0)=0;W(self,0xd4)=0;W(self,0xd8)=0;W(self,0x16c)=0;W(self,0x174)=0;ResourceStringLoader_Reset(self+0xdc);TextLayout_InitializeSelectionPanel(self+0x178);memset(self+0x3b0,-1,32);}
