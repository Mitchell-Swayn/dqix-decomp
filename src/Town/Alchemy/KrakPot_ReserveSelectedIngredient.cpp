#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x02159108; symbol: func_ov006_02159108; size: 0x94.
extern "C" void KrakPot_ReserveSelectedIngredient(char *self, int index, int key, int amount) {
    short **keyRows = *(short ***)(self + 0x48);
    unsigned char **valueRows = *(unsigned char ***)(self + 0x4c);
    unsigned short *counts = *(unsigned short **)(self + 0x50);
    short *keys = keyRows[index];
    unsigned char *values = valueRows[index];
    unsigned short count = counts[index];
    for (unsigned short i = 0; i < count; ++i) {
        if (key == keys[i]) values[i] -= amount;
    }
    for (unsigned char i = 0; i < 3; ++i) {
        if (*(short *)(self + i * 2 + 0x378) <= 0) {
            *(short *)(self + i * 2 + 0x372) = index;
            *(short *)(self + i * 2 + 0x378) = key;
            *(unsigned char *)(self + i + 0x38c) = amount;
            return;
        }
    }
}
