#include <globaldefs.h>
ARM
extern "C" unsigned char* KrakPot_FindLayoutHitRegion(void*, int);
// Original: arm9/ov006 @ 0x021573C8; symbol: func_ov006_021573c8; size: 0x94.
extern "C" void KrakPot_ConfigureIngredientPickerHitRegions(void *self) {
    unsigned char *record = KrakPot_FindLayoutHitRegion(self, 0x50);
    if (record) record[0x16] &= ~1;
    record = KrakPot_FindLayoutHitRegion(self, 0x4f);
    if (record) record[0x16] &= ~1;
    record = KrakPot_FindLayoutHitRegion(self, 0x0e);
    if (record) record[0x16] &= ~1;
    record = KrakPot_FindLayoutHitRegion(self, 0x0f);
    if (record) record[0x16] &= ~1;
    record = KrakPot_FindLayoutHitRegion(self, 0x15);
    if (record) record[0x16] |= 1;
}
