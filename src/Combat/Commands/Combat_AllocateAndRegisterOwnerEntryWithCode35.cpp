#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned int code);
// Original: arm9/ov000 @ 0x0216B464; symbol: Combat_AllocateAndRegisterOwnerEntryWithCode35; size: 0x14.
// Invokes the owner-entry allocator with code 0x35 and returns one.
extern "C" int Combat_AllocateAndRegisterOwnerEntryWithCode35(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x35);
    return 1;
}
