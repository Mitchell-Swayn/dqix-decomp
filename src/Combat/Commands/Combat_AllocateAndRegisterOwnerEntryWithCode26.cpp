#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned int code);
// Original: arm9/ov000 @ 0x0216ADB8; symbol: Combat_AllocateAndRegisterOwnerEntryWithCode26; size: 0x14.
// Invokes the owner-entry allocator with code 0x26 and returns one.
extern "C" int Combat_AllocateAndRegisterOwnerEntryWithCode26(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x26);
    return 1;
}
