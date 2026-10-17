#include <globaldefs.h>
ARM
extern "C" void *data_ov031_02290d0c;
extern "C" int Network_StartExtendedScan(void *, void *);
extern "C" int func_ov031_022376fc(void);
// Original: arm9/ov031 @ 0x022375CC; symbol: func_ov031_022375cc; size: 0x34.
extern "C" int CheckCurrentContextStatus(void) {
    return Network_StartExtendedScan((void *)func_ov031_022376fc,
                         (unsigned char *)data_ov031_02290d0c + 0x1374) == 2;
}
