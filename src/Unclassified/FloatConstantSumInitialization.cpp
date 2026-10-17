// Original: arm9/main @ 0x020E5E2C; symbol: __sinit_020e5e2c; size: 0x88.
#include <globaldefs.h>
extern "C" float data_020f0420[5];
extern "C" float data_021079cc[5];
// ARM9 main, original ABI initializer __sinit_020e5e2c at 0x020e5e2c.
// Initializes a float sum table; the ABI-required initializer name is preserved.
#pragma define_section init ".init" RX
extern "C" ARM __declspec(section "init") void __sinit_020e5e2c(void)
{
    data_021079cc[1] = data_020f0420[3] + (data_020f0420[0] + (data_020f0420[4] + data_020f0420[2]));
    float sum = data_021079cc[0] + data_020f0420[4];
    float addend = data_020f0420[2];
    data_021079cc[4] = sum;
    sum += addend;
    addend = data_020f0420[0];
    data_021079cc[3] = sum;
    sum += addend;
    data_021079cc[2] = sum;
}
