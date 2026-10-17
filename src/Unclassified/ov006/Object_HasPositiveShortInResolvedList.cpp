#include <globaldefs.h>
ARM
extern "C" short* func_ov006_0215919c(void*);
extern "C" unsigned Unclassified_GetTableHalfwordByObjectIndexMinus5B(void*);
// Original: arm9/ov006 @ 0x02159218; symbol: func_ov006_02159218; size: 0x5C.
extern "C" int Object_HasPositiveShortInResolvedList(void* self) {
    short* values = func_ov006_0215919c(self);
    unsigned count = Unclassified_GetTableHalfwordByObjectIndexMinus5B(self);
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
