#include <globaldefs.h>
ARM
#include <Memory/SafeAllocator.h>
extern unsigned char data_02114e20[];extern "C" void Graphics_FinalizeDisplayStateAndRestoreControls(unsigned);extern "C" void OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(int);extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);extern "C" void func_020a0c0c();
// Original: arm9/main @ 0x020DAE08; symbol: func_020dae08; size: 0x60.
extern "C" void CleanupOverlayObjectAndOwnedAllocator(unsigned char* object){if(*(unsigned*)(object+12)){Graphics_FinalizeDisplayStateAndRestoreControls(*(unsigned*)(object+12));*(unsigned*)(object+12)=0;OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(1);}SignedAllocatorHeader* allocator=((SafeAllocator*)(object+20))->GetSignedAllocator();if(allocator){((SafeAllocator*)(object+20))->Destroy();Memory_FreeThroughAllocatorUnion(data_02114e20,allocator);}func_020a0c0c();object[1]=1;}
