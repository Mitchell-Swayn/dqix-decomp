#include <globaldefs.h>
ARM
extern "C" void ReleaseNestedAllocatorStorage();
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
// Original: arm9/ov003 @ 0x0217E67C; symbol: System_ClearConditionalOverlayFieldAndDestroyAllocator; size: 0x34.
// When object +0x1c is set, calls an overlay cleanup helper, clears the field, and notifies the global stack; always destroys allocator +8.
extern "C" void System_ClearConditionalOverlayFieldAndDestroyAllocator(unsigned char* self) {
    if (*(unsigned int*)(self + 0x1c)) {
        ReleaseNestedAllocatorStorage();
        *(unsigned int*)(self + 0x1c) = 0;
        OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);
    }
    _ZN13SafeAllocator7DestroyEv(self + 8);
}
