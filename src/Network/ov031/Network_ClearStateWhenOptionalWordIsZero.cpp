#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290ca0[];
extern "C" char *GetSharedObjectRegionAtOffset1024(void);
extern "C" void ReadOptionalSharedWords18And1C(unsigned *, unsigned *);
// Original: arm9/ov031 @ 0x0222EE34; symbol: func_ov031_0222ee34; size: 0x3C.
extern "C" void Network_ClearStateWhenOptionalWordIsZero(void) {
    GetSharedObjectRegionAtOffset1024();
    unsigned int value;
    ReadOptionalSharedWords18And1C(0, &value);
    switch (value) {
    case 0:
        *(unsigned short *)(data_ov031_02290ca0 + 4) = 0;
        data_ov031_02290ca0[0] = 0;
        data_ov031_02290ca0[2] = 0;
        break;
    default:
        return;
    }
}
