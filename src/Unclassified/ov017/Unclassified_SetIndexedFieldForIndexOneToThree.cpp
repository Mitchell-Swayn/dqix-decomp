#include <globaldefs.h>
ARM
extern "C" void func_ov017_02195214(void *, void *);
// Original: arm9/ov017 @ 0x02195494; symbol: func_ov017_02195494; size: 0x30.
extern "C" void Unclassified_SetIndexedFieldForIndexOneToThree(void *object, int index, void *value) {
    --index;
    if (index < 0 || index > 2)
        return;
    func_ov017_02195214(value, (unsigned char *)object + 0x42F1 + index * 15);
}
