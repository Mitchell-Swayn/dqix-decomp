#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned int code);
// Original: arm9/ov000 @ 0x0216AD90; symbol: Combat_AllocateAndRegisterOwnerEntryWithCode24; size: 0x14.
// Invokes the owner-entry allocator with code 0x24 and returns one.
extern "C" int Combat_AllocateAndRegisterOwnerEntryWithCode24(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x24);
    return 1;
}
