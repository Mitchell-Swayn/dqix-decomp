#include <globaldefs.h>
ARM
extern "C" void ItemDetail_SetBatchQuantity(void *);
// Original: arm9/ov006 @ 0x021571B8; symbol: func_ov006_021571b8; size: 0x14.
extern "C" void KrakPot_SetRecipeDisplayBatchQuantity(void *p) {
    ItemDetail_SetBatchQuantity((char *)p + 0xae4);
}
