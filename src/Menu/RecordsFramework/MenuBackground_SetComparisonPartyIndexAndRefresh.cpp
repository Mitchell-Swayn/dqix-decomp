#include <globaldefs.h>
ARM
extern "C" void ItemDetail_RenderEquipmentStatComparison(void *, unsigned int);
// Original: arm9/ov023 @ 0x021FBDF4; symbol: func_ov023_021fbdf4; size: 0x14.
extern "C" void MenuBackground_SetComparisonPartyIndexAndRefresh(void *p, unsigned int value) {
    *((unsigned char *)p + 0x79a) = value;
    ItemDetail_RenderEquipmentStatComparison((unsigned char *)p + 0x20, value);
}
