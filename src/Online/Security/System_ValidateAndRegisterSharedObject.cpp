#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x0221E5C8; symbol: System_ValidateAndRegisterSharedObject; size: 0x8.
// Forwards the current shared object to the routine that validates its state and registers its callback record.
extern "C" int NetworkSocket_Close(void *object);
extern "C" int System_ValidateAndRegisterSharedObject(void *object) {
    return NetworkSocket_Close(object);
}
