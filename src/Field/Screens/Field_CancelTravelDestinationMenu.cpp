#include <globaldefs.h>
ARM
extern "C" void Field_ReleaseTravelDestinationMenuResources(void *);
// Original: arm9/ov017 @ 0x021A9314; symbol: Object_CancelBackgroundLoadResetDisplayAndMarkComplete; size: 0x18.
// Calls the helper that cancels background work, releases its allocator, clears a resource flag, and updates display control; then sets byte +1.
extern "C" void Field_CancelTravelDestinationMenu(unsigned char *p) {
    Field_ReleaseTravelDestinationMenuResources(p);
    p[1] = 1;
}
