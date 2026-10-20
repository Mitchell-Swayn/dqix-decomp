#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
struct State;
extern "C" void Selection_InitializeDisplayController(State*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
extern "C" void Graphics_InitializeSpriteTransformDefaults(State*);
extern "C" void SpriteAnimation_ResetTrackList(unsigned*);
// Original: arm9/ov003 @ 0x0216AE0C; symbol: Inn_AllocateServiceMenuResources; size: 0x108.
// Allocates and initializes grid, canvas, text, scale-entry and output buffers.
extern "C" void Inn_AllocateServiceMenuResources(char* self,SafeAllocator* allocator){
 if(!allocator)return;
 *(SafeAllocator**)(self+0x12d0)=allocator;
 *(void**)(self+0x12c0)=allocator->Allocate(0xbc);
 *(void**)(self+0x12c4)=(*(SafeAllocator**)(self+0x12d0))->Allocate(0x40);
 *(void**)(self+0x12c8)=(*(SafeAllocator**)(self+0x12d0))->Allocate(0xe0);
 Selection_InitializeDisplayController(*(State**)(self+0x12c0));
 for(int i=0;i<2;++i)Graphics_InitializeCanvasTransferState(*(char**)(self+0x12c4)+i*0x20);
 for(int i=0;i<1;++i)TextCanvas_InitializeLayoutAndTransferDefaults(*(unsigned char**)(self+0x12c8)+i*0xe0);
 *(void**)(self+0x1264)=(*(SafeAllocator**)(self+0x12d0))->Allocate(0x258);
 *(void**)(self+0x1268)=(*(SafeAllocator**)(self+0x12d0))->Allocate(8);
 for(int i=0;i<15;++i)Graphics_InitializeSpriteTransformDefaults((State*)(*(char**)(self+0x1264)+i*0x28));
 SpriteAnimation_ResetTrackList(*(unsigned**)(self+0x1268));
}
