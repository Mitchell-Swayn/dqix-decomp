#include <globaldefs.h>
ARM
extern "C" {
extern void *data_ov001_021658b8[8];
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
void _ZN13SafeAllocator7DestroyEv(void*);
// Original: arm9/ov001 @ 0x0215AA5C; symbol: func_ov001_0215aa5c; size: 0x4C.
void Memory_DestroyEightSignedAllocators(void) {
    for (int i = 0; i < 8; i++) {
        if (data_ov001_021658b8[i] && _ZNK13SafeAllocator18GetSignedAllocatorEv(data_ov001_021658b8[i])) {
            _ZN13SafeAllocator7DestroyEv(data_ov001_021658b8[i]);
            data_ov001_021658b8[i] = 0;
        }
    }
}
}
