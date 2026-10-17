#include <globaldefs.h>
ARM
extern "C" void ZeroSixByteRecord(unsigned char *p);
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void *ReadGlobalValueAt02153637(void);
extern "C" void RecordArray_SetFirstEmptyFlagWhenModeEnabled(unsigned char *p, unsigned char v);
// Original: arm9/ov017 @ 0x0218D7B0; symbol: func_ov017_0218d7b0; size: 0x4C.
extern "C" void RecordArray_CopySixByteEntryAndRefreshFlag(unsigned char *base, const unsigned char *source) {
    if (source == 0) {
        return;
    }
    ZeroSixByteRecord(base + 0x4356);
    memcpy(base + 0x4356, source, 6);
    base[0x435B] = 1;
    RecordArray_SetFirstEmptyFlagWhenModeEnabled((unsigned char *)ReadGlobalValueAt02153637(), 1);
}
