#include <globaldefs.h>
extern "C" int UpdateSlotValueThroughResolver(void*, void*);
extern "C" void InitializeRelocatedBlobPointersAndMarkProcessed(void*, void*, unsigned char*, int (*)(void*, void*));
// The callee initializes this output byte before testing or consuming it.
// Original: arm9/main @ 0x020E038C; symbol: func_020e038c; size: 0x2C.
extern "C" int InitializeSerializedStateWhenDataPresent(void* state, void* data, void* required)
{
    if (data && required) {
        unsigned char initialized;
        InitializeRelocatedBlobPointersAndMarkProcessed(state, data, &initialized, UpdateSlotValueThroughResolver);
        return 1;
    }
    return 0;
}
