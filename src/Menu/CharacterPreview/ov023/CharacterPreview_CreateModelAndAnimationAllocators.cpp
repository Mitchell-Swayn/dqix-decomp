#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" unsigned int CharacterPreviewCreateModelAndAnimationAllocators_UnknownRoleInitializedBytes[];
// Original: arm9/ov023 @ 0x021E4F64; symbol: CharacterPreview_CreateModelAndAnimationAllocators; size: 0x74.
// Creates ten child allocators from the size table, then one 0x1000-byte child.
extern "C" void CharacterPreview_CreateModelAndAnimationAllocators(unsigned char* self, SafeAllocator* parent) {
    for (int index = 0; index < 10; ++index) {
        unsigned int size = CharacterPreviewCreateModelAndAnimationAllocators_UnknownRoleInitializedBytes[index];
        void* buffer = parent->Allocate(size);
        ((SafeAllocator*)(self + 0x6b8))[index].CreateTypeA(buffer, size);
    }
    void* buffer = parent->Allocate(0x1000);
    ((SafeAllocator*)(self + 0x780))->CreateTypeA(buffer, 0x1000);
}
