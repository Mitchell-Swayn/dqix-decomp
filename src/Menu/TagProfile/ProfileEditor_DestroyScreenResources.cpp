#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#define R32(a) (*(volatile unsigned*)(a))
#define R16(a) (*(volatile unsigned short*)(a))
extern "C" {void* DisplayContext_GetGlobalInstance();void BackgroundLoader_CancelEightTasksAndResetState(void*);void Graphics_ApplyMainBackgroundSnapshotAndClearPending(void*);void Window_ClearResourceBuffers(void*);void Graphics_ResetCountedThirtyTwoByteTransfers(void*);void Window_ResetResourceTransfers(void*);void Selection_ReleaseAttachedDisplayResources(void*);void* memset(void*,int,unsigned);void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);void _ZN13SafeAllocator7DestroyEv(void*);}
// Original: arm9/ov012 @ 0x02185AF0; symbol: Graphics_ClearDisplayResourcesAndDestroyFiveArenas; size: 0x100.
// Clears staged display resources and destroys each allocated arena in a five-entry array.
extern "C" void ProfileEditor_DestroyScreenResources(unsigned char* self){BackgroundLoader_CancelEightTasksAndResetState(DisplayContext_GetGlobalInstance());R32(0x04000000)=(R32(0x04000000)&~0x1f00)|0x100;R16(0x04000050)=0;Graphics_ApplyMainBackgroundSnapshotAndClearPending(self+8);Window_ClearResourceBuffers(self+0xac);Graphics_ResetCountedThirtyTwoByteTransfers(self+0xac);Window_ResetResourceTransfers(self+0xac);Selection_ReleaseAttachedDisplayResources(self+0xac);memset(P(self,0x137c),0,32);_Z25CleanInvalidateCacheRangePKvj(P(self,0x137c),32);LoadToMainBG1CharacterData(P(self,0x137c),0,32);W(self,0x1374)=0;W(self,0x137c)=0;void* heaps[5]={self+0x20,self+0x34,self+0x48,self+0x5c,self+0x70};for(int i=0;i<5;++i){void* heap=heaps[i];if(_ZNK13SafeAllocator18GetSignedAllocatorEv(heap))_ZN13SafeAllocator7DestroyEv(heap);}}
