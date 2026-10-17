#include <globaldefs.h>
ARM
extern "C" {
extern unsigned data_ov016_0219d1c0[];
extern unsigned char data_ov016_0219ca60[];
void MIi_CpuCopyFast(const void*, void*, unsigned);
}
// Original: arm9/ov016 @ 0x0218FE30; symbol: func_ov016_0218fe30; size: 0x70.
extern "C" void *GetOrCopyGeometryDataChunk() {
    if (!data_ov016_0219d1c0[8]) {
        if (data_ov016_0219d1c0[3] >= 0x180) {
            data_ov016_0219d1c0[8] = data_ov016_0219d1c0[4];
            MIi_CpuCopyFast(data_ov016_0219ca60, (void *)data_ov016_0219d1c0[4], 0x180);
            data_ov016_0219d1c0[4] += 0x180;
            data_ov016_0219d1c0[3] -= 0x180;
        } else return data_ov016_0219ca60;
    }
    return (void *)data_ov016_0219d1c0[8];
}
