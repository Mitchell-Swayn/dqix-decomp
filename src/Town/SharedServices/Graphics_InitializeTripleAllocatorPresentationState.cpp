#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void VectorizedMemset(void*,int,unsigned);void SubBackground_InitializeController(void*);void Graphics_InitializeSpriteResourceBuffers(unsigned char*);void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);void MessageTextTable_Reset(void*);void Graphics_InitializeObjectAndTwoCanvasTransfers(void*);}
// Original: arm9/ov003 @ 0x02173C40; symbol: Graphics_InitializeTripleAllocatorPresentationState; size: 0x100.
// Clears presentation buffers and initializes three allocators, records and two canvas transfers.
extern "C" void Graphics_InitializeTripleAllocatorPresentationState(unsigned char* self){self[0]=0;self[1]=0;H(self,2)=-1;VectorizedMemset(self+4,0,64);VectorizedMemset(self+0x44,0,128);self[0xc4]=0;self[0xca]=0;self[0xcb]=0;self[0xcc]=0;H(self,0xc6)=0;H(self,0xc8)=0;W(self,0xd0)=0;self[0xd4]=0;self[0xd5]=0;SubBackground_InitializeController(self+0xd8);self[0xec]=0;self[0xed]=0;self[0xee]=0;self[0xef]=0;W(self,0xf0)=-1;W(self,0xf4)=-1;self[0x10a]=0;self[0x10b]=0;self[0x11c]=0;self[0x11d]=0;W(self,0x120)=0;W(self,0x124)=0;W(self,0x128)=0;W(self,0x12c)=0;Graphics_InitializeSpriteResourceBuffers(self+0x130);_ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x184);_ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x198);_ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x1ac);W(self,0x1c0)=0;W(self,0x1c4)=0;MessageTextTable_Reset(self+0x1c8);MessageTextTable_Reset(self+0x1d0);MessageTextTable_Reset(self+0x1d8);Graphics_InitializeObjectAndTwoCanvasTransfers(self+0x1e0);self[0x344]=0;}
