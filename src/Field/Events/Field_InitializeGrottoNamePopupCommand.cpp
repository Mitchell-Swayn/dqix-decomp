#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
extern "C" void ResourceStringLoader_Reset(char *);
// Original: arm9/ov017 @ 0x021BEBA4; symbol: InitializeType0x34RecordAndInvalidIndices; size: 0x5C.
// Initializes a type-0x34 object, marks eleven words invalid, resets state and allocator fields, and clears the trailing record and indices.
extern "C" void Field_InitializeGrottoNamePopupCommand(signed char *obj) {
    LinkedQueue_InitializeNodeStatus(obj);
    *obj = 0x34;
    for (int i = 0; i < 0xb; ++i) *(int *)(obj + 8 + i * 4) = -1;
    *(unsigned char *)(obj + 0x34) = 0;
    *(int *)(obj + 0x38) = 0;
    *(int *)(obj + 0x40) = -1;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(obj + 0x44);
    ResourceStringLoader_Reset((char *)obj + 0x58);
}
