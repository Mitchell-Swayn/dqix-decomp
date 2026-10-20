#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned int code);
// Original: arm9/ov000 @ 0x0216B870; symbol: Combat_AllocateAndRegisterOwnerEntryWithCode3C; size: 0x14.
// Invokes the owner-entry allocator with code 0x3c and returns one.
extern "C" int Combat_AllocateAndRegisterOwnerEntryWithCode3C(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x3c);
    return 1;
}
