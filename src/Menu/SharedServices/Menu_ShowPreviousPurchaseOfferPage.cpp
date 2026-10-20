#include <globaldefs.h>
ARM
extern "C" void *Menu_FindInventoryGridByKey(void *, unsigned);
extern "C" void Menu_RefreshSixOfferRows(void *);
// Original: arm9/ov004 @ 0x0215CDF0; symbol: func_ov004_0215cdf0; size: 0x48.
extern "C" int Menu_ShowPreviousPurchaseOfferPage(void *owner) {
    unsigned char *object = (unsigned char *)Menu_FindInventoryGridByKey(owner, 0x5b);
    short first = *(short *)(object + 0x5c);
    short second = *(short *)(object + 0x5e);
    --first;
    if (first < 0) first = second - 1;
    *(short *)(object + 0x5c) = first;
    *(short *)(object + 0x5e) = second;
    Menu_RefreshSixOfferRows(owner);
    return 0;
}
