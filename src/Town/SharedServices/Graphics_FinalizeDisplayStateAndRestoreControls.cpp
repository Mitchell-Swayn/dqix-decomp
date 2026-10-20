#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void Graphics_ResetLoadedLayerResources(unsigned char*);
extern "C" void TextCanvas_ResetWithTilemapResource(int);
extern "C" void SpriteAnimation_ClearTrackList(unsigned*);
extern "C" void Graphics_FinalizeSpriteResourceBuffers(void*);
extern "C" void Selection_ReleaseAttachedDisplayResources(unsigned char*);
extern "C" void CancelOwnerTaskAndResetEmbeddedState(void*);
// Original: arm9/ov003 @ 0x0217DB88; symbol: func_ov003_0217db88; size: 0xB8.
extern "C" void Graphics_FinalizeDisplayStateAndRestoreControls(unsigned char* p){
 Selection_ReleaseAttachedDisplayResources(*(unsigned char**)(p+0x90));
 for(int i=0;i<2;i++)Graphics_ResetLoadedLayerResources(*(unsigned char**)(p+0x94)+i*32);
 for(int i=0;i<1;i++)TextCanvas_ResetWithTilemapResource((int)(*(unsigned char**)(p+0x98)+i*224));
 SpriteAnimation_ClearTrackList(*(unsigned**)(p+0x38));
 if(_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0xa4))_ZN13SafeAllocator7DestroyEv(p+0xa4);
 if(_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0xb8))_ZN13SafeAllocator7DestroyEv(p+0xb8);
 Graphics_FinalizeSpriteResourceBuffers(p+0x3c);
 CancelOwnerTaskAndResetEmbeddedState(p+0xcc);
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|(*(unsigned*)p<<8);
}
