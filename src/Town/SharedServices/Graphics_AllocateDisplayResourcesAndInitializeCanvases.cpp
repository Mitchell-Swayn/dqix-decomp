#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
struct State;
extern "C" {
char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
void _ZN13SafeAllocator5ResetEv(void*);
void Window_AllocateAndInitializeEntryArraysAndControls(unsigned char*,unsigned,unsigned,unsigned,SafeAllocator*,int,unsigned char);
void Graphics_InitializeCanvasTransferState(char*);
void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
void DisplayLayout_Initialize(char*);
void Graphics_InitializeSpriteTransformDefaults(State*);
void* _ZN9GameState11GetInstanceEv();
void Graphics_ResetCanvasAndCaptureSubBackgroundState(void*);
void Alltrades_AllocateVocationPreviewArena(unsigned char**,void*);
// Original data: arm9/ov003 @ 0x217f320; symbol: data_ov003_0217f320.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00380000002800000014000000040000000c0000008000000004000000880000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern unsigned GraphicsAllocateDisplayResourcesAndInitializeCanvases_UnknownRoleInitializedBytes[];
}
struct AllocationSizes { unsigned value[8]; };
// Original: arm9/ov003 @ 0x021544EC; symbol: func_ov003_021544ec; size: 0x234.
// Allocates display resource pools and initializes their canvas and entry storage.
extern "C" void Graphics_AllocateDisplayResourcesAndInitializeCanvases(unsigned char* self,unsigned allocator) {
    if(allocator==0)return;
    *(char**)(self+0x00)=_ZN13SafeAllocator8AllocateEj(allocator,0xa0);
    *(char**)(self+0x04)=_ZN13SafeAllocator8AllocateEj(allocator,0x60);
    *(char**)(self+0x0c)=_ZN13SafeAllocator8AllocateEj(allocator,0x4c00);
    *(char**)(self+0x10)=_ZN13SafeAllocator8AllocateEj(allocator,0x40);
    *(char**)(self+0x14)=_ZN13SafeAllocator8AllocateEj(allocator,0x2a0);
    *(char**)(self+0x18)=_ZN13SafeAllocator8AllocateEj(allocator,0x80);
    *(char**)(self+0x20)=_ZN13SafeAllocator8AllocateEj(allocator,0x30);
    *(char**)(self+0x24)=_ZN13SafeAllocator8AllocateEj(allocator,0x190);
    *(char**)(self+0x28)=_ZN13SafeAllocator8AllocateEj(allocator,8);
    *(char**)(self+0x1c)=_ZN13SafeAllocator8AllocateEj(allocator,0x24);
    Window_AllocateAndInitializeEntryArraysAndControls(*(unsigned char**)(self+0x1c),0,1,(unsigned)(*(void**)(self+0x28)),(SafeAllocator*)allocator,4,0x40);
    AllocationSizes sizes=*(AllocationSizes*)GraphicsAllocateDisplayResourcesAndInitializeCanvases_UnknownRoleInitializedBytes;
    for(unsigned char i=0;i<8;i++) {
        unsigned offset=i*0x14;
        char* pool=(char*)*(void**)(self+0x00)+offset;
        unsigned size=sizes.value[i];
        _ZN13SafeAllocator21ResetAllocatorPointerEv(pool);
        char* memory=_ZN13SafeAllocator8AllocateEj(allocator,size);
        _ZN13SafeAllocator11CreateTypeAEPvj(pool,memory,size);
        _ZN13SafeAllocator5ResetEv(pool);
    }
    for(unsigned char i=0;i<2;i++) Graphics_InitializeCanvasTransferState(*(char**)(self+0x10)+i*0x20);
    for(unsigned char i=0;i<3;i++) TextCanvas_InitializeLayoutAndTransferDefaults((unsigned char*)*(char**)(self+0x14)+i*0xe0);
    DisplayLayout_Initialize(*(char**)(self+0x18));
    for(unsigned char i=0;i<12;i++) *(unsigned*)(*(char**)(self+0x20)+i*4)=0;
    for(unsigned char i=0;i<10;i++) Graphics_InitializeSpriteTransformDefaults((State*)(*(char**)(self+0x24)+i*0x28));
    _ZN9GameState11GetInstanceEv();
    unsigned char* nested=(unsigned char*)*(void**)(self+4);
    Graphics_ResetCanvasAndCaptureSubBackgroundState(nested);
    Alltrades_AllocateVocationPreviewArena((unsigned char**)nested,(void*)allocator);
    *(void**)(nested+8)=self+0x90;
    *(void**)(nested+4)=self+0xfc;
    *(void**)(nested+0xc)=self+0x114;
    *(signed char*)(nested+0x59)=-1;
}
