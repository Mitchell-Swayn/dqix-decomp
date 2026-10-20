#include <globaldefs.h>
ARM
extern "C" short* KrakPot_GetSelectedCategoryItemIds(void*);
extern "C" unsigned KrakPot_GetSelectedCategoryItemCount(void*);
// Original: arm9/ov006 @ 0x02159218; symbol: func_ov006_02159218; size: 0x5C.
extern "C" int KrakPot_HasItemsInSelectedCategory(void* self) {
    short* values = KrakPot_GetSelectedCategoryItemIds(self);
    unsigned count = KrakPot_GetSelectedCategoryItemCount(self);
    int found = 0;
    if (values != 0) {
        unsigned short i = 0;
        while (i < count) {
            if (values[i] > 0) {
                found = 1;
                break;
            }
            ++i;
        }
    }
    return found;
}
