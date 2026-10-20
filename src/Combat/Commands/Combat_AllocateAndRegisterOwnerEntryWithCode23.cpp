#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned int code);
// Original: arm9/ov000 @ 0x0216AD7C; symbol: Combat_AllocateAndRegisterOwnerEntryWithCode23; size: 0x14.
// Invokes the owner-entry allocator with code 0x23 and returns one.
extern "C" int Combat_AllocateAndRegisterOwnerEntryWithCode23(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x23);
    return 1;
}
