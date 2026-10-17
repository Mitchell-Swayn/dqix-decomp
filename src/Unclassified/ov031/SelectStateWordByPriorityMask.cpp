#include <globaldefs.h>
extern "C" {
extern int data_ov031_0224e5c4[];
}
// Original: arm9/ov031 @ 0x022133F8; symbol: func_ov031_022133f8; size: 0x58.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM int SelectStateWordByPriorityMask(unsigned mask)
{
    if(mask&1) return data_ov031_0224e5c4[3];
    if(mask&2) return data_ov031_0224e5c4[0];
    if(mask&4) return data_ov031_0224e5c4[1];
    if(mask&8) return data_ov031_0224e5c4[2];
    if(mask&16) return data_ov031_0224e5c4[4];
    return 0;
}
