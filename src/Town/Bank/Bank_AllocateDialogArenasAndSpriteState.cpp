#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);}extern "C" {void Graphics_InitializeSpriteTransformDefaults(void*);void SpriteAnimation_ResetTrackList(void*);unsigned char* TextContext_GetSharedInstance();}
// Original: arm9/ov003 @ 0x021680D4; symbol: Memory_InitializeSelectionArenasAndSixteenRecords; size: 0xf4.
// Initializes five arenas, sixteen fixed-point records and shared graphics output.
extern "C" void Bank_AllocateDialogArenasAndSpriteState(unsigned char* self,void* heap){if(!heap)return;_ZN13SafeAllocator11CreateTypeAEPvj(self+0,_ZN13SafeAllocator8AllocateEj(heap,16384),16384);_ZN13SafeAllocator11CreateTypeAEPvj(self+20,_ZN13SafeAllocator8AllocateEj(heap,32768),32768);_ZN13SafeAllocator11CreateTypeAEPvj(self+40,_ZN13SafeAllocator8AllocateEj(heap,28672),28672);_ZN13SafeAllocator11CreateTypeAEPvj(self+60,_ZN13SafeAllocator8AllocateEj(heap,4096),4096);_ZN13SafeAllocator11CreateTypeAEPvj(self+80,_ZN13SafeAllocator8AllocateEj(heap,1024),1024);P(self,0x4d4)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(heap,640);for(int i=0;i<16;++i)Graphics_InitializeSpriteTransformDefaults(P(self,0x4d4)+i*40);P(self,0x4d8)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(heap,8);SpriteAnimation_ResetTrackList(P(self,0x4d8));P(self,0x7c)=P(TextContext_GetSharedInstance(),0x5c);}
