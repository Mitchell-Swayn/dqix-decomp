#include <globaldefs.h>
ARM
extern "C" unsigned int DisplayContext_GetGlobalInstance();
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(int);
extern "C" void Graphics_ApplyMainBackgroundSnapshotAndClearPending(void*);
extern "C" void Window_ClearResourceBuffers(unsigned char*);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void*);
extern "C" void Window_ResetResourceTransfers(void*);
extern "C" void Selection_ReleaseAttachedDisplayResources(unsigned char*);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*, unsigned);
extern "C" void LoadToMainBG1CharacterData(const void*, unsigned int, unsigned int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
// Original: arm9/ov008 @ 0x021894b8; Graphics_ResetOverlayDisplayAndOwnedResources; 240 bytes
extern "C" void PartyTalk_DestroyProfileSessionResources(void* p) {
 BackgroundLoader_CancelEightTasksAndResetState(DisplayContext_GetGlobalInstance());
 volatile unsigned int* display = (volatile unsigned int*)0x04000000;
 *display = (*display & ~0x1f00) | 0x100;
 *(volatile unsigned short*)((char*)display + 0x50) = 0;
 Graphics_ApplyMainBackgroundSnapshotAndClearPending(p);
 Window_ClearResourceBuffers((unsigned char*)p + 0x18);
 Graphics_ResetCountedThirtyTwoByteTransfers((char*)p + 0x18);
 Window_ResetResourceTransfers((char*)p + 0x18);
 Selection_ReleaseAttachedDisplayResources((unsigned char*)p + 0x18);
 if (*(void**)((char*)p + 0x2a4)) {
  memset(*(void**)((char*)p + 0x2a4), 0, 0x20);
  _Z25CleanInvalidateCacheRangePKvj(*(void**)((char*)p + 0x2a4), 0x20);
  LoadToMainBG1CharacterData(*(void**)((char*)p + 0x2a4), 0, 0x20);
 }
 *(void**)((char*)p + 0x2a0) = 0;
 *(void**)((char*)p + 0x2a4) = 0;
 void** allocators[4];
 allocators[0] = (void**)((char*)p + 0x200);
 allocators[1] = (void**)((char*)p + 0x214);
 allocators[2] = (void**)((char*)p + 0x228);
 allocators[3] = (void**)((char*)p + 0x23c);
 for (int i = 0; i < 4; ++i) {
  void* allocator = (void*)allocators[i];
  if (_ZNK13SafeAllocator18GetSignedAllocatorEv(allocator)) _ZN13SafeAllocator7DestroyEv(allocator);
 }
}
