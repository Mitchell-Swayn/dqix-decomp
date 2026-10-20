#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021DCED4; symbol: Unclassified_SetByteAtOffset799; size: 0x8.
// Stores the supplied byte at object offset 0x799.
extern "C" void ItemDetail_SetBatchQuantity(void* object, unsigned char value) {
    ((unsigned char*)object)[0x799] = value;
}
