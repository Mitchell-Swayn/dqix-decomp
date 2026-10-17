#include <globaldefs.h>
ARM

extern "C" void *func_ov017_0219bddc(unsigned char *);
extern "C" void Ov017_RegisterZoneTintRecord(unsigned char, unsigned);

// Original: arm9/ov017 @ 0x0219BED0; symbol: func_ov017_0219bed0; size: 0x34.
extern "C" void *Unclassified_InitializeAndApplyOptionalValue(unsigned value) {
    unsigned char argument = 0;
    void *result = func_ov017_0219bddc(&argument);
    if (result != 0) {
        Ov017_RegisterZoneTintRecord(argument, value);
    }
    return result;
}
