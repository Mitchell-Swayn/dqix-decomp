#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021DBB34; symbol: Unclassified_DecodePackedTransform; size: 0x124.
// Converts packed transform components into the caller's twelve-float buffer.
extern "C" void ItemDetail_DecodeEquipmentStatModifiers(const int *const *source, float *output)
{
    if (source == 0 || output == 0) return;
    const int *packed = *source;
    if (packed == 0) return;
    output[0] = (float)(packed[2] << 22 >> 22);
    output[1] = (float)(packed[2] << 12 >> 22);
    output[2] = (float)((unsigned int)packed[2] << 2 >> 22) / 10.0f;
    output[3] = (float)((unsigned int)(packed[3] << 22) >> 22) / 10.0f;
    output[4] = (float)((unsigned int)packed[3] << 12 >> 22) / 10.0f;
    output[5] = 0.0f;
    output[6] = (float)(packed[4] << 22 >> 22);
    output[7] = (float)(packed[4] << 12 >> 22);
    output[8] = (float)(packed[4] << 2 >> 22);
    output[9] = (float)(packed[5] << 22 >> 22);
    output[10] = (float)(packed[5] << 12 >> 22);
    output[11] = (float)(packed[5] << 2 >> 22);
}
