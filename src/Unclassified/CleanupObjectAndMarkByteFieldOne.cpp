#include <globaldefs.h>

extern "C" void CleanupOverlayObjectAndOwnedAllocator(void*);

// Original: arm9/main @ 0x020DAE98; symbol: func_020dae98; size: 0x18.
extern "C" ARM void CleanupObjectAndMarkByteFieldOne(unsigned char* object) {
    CleanupOverlayObjectAndOwnedAllocator(object);
    object[1] = 1;
}
