#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);void Selection_InitializeDisplayController(void*);void Graphics_InitializeCanvasTransferState(char*);void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);void Graphics_InitializeSpriteTransformDefaults(void*);void SpriteAnimation_ResetTrackList(unsigned*);void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);}
// Original: arm9/ov003 @0x0217cd24; symbol:Graphics_AllocateGridCanvasesAndNestedArenas; size:0x118.
// Allocates grid, canvas, seven display records and two nested allocator arenas through supplied allocator.
extern "C" void Town_AllocateDestinationMenuResources(unsigned char* self,void* allocator){if(!allocator)return;P(self,0xa0)=(unsigned char*)allocator;P(self,0x90)=(unsigned char*)_ZN13SafeAllocator8AllocateEj((unsigned)allocator,188);P(self,0x94)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(W(self,0xa0),64);P(self,0x98)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(W(self,0xa0),224);Selection_InitializeDisplayController(P(self,0x90));for(int i=0;i<2;++i)Graphics_InitializeCanvasTransferState((char*)P(self,0x94)+i*32);for(int i=0;i<1;++i)TextCanvas_InitializeLayoutAndTransferDefaults(P(self,0x98)+i*224);P(self,0x34)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(W(self,0xa0),280);P(self,0x38)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(W(self,0xa0),8);for(int i=0;i<7;++i)Graphics_InitializeSpriteTransformDefaults(P(self,0x34)+i*40);SpriteAnimation_ResetTrackList((unsigned*)P(self,0x38));void* block=_ZN13SafeAllocator8AllocateEj(W(self,0xa0),2048);_ZN13SafeAllocator11CreateTypeAEPvj(self+0xa4,block,2048);block=_ZN13SafeAllocator8AllocateEj(W(self,0xa0),1024);_ZN13SafeAllocator11CreateTypeAEPvj(self+0xb8,block,1024);}
