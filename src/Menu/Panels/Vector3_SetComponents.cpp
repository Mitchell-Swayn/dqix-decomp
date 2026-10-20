#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F00F4; symbol: Unclassified_SetThreeWordFields; size: 0x8.
// Stores three supplied words to consecutive fields at the destination; caller passes three calculated coordinate words.
extern "C" void Vector3_SetComponents(unsigned* destination, unsigned first, unsigned second, unsigned third) {
    destination[0] = first;
    destination[1] = second;
    destination[2] = third;
}
