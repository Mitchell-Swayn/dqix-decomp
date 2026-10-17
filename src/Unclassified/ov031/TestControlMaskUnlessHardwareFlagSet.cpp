extern "C"
{
    extern unsigned short *data_ov031_02290d40[];
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov031 @ 0x0223D394; symbol: func_ov031_0223d394; size: 0x40.
extern "C" bool TestControlMaskUnlessHardwareFlagSet(unsigned mask)
{
    if(((*(volatile unsigned short*)0x027fffa8)&0x8000)>>15)return false;
    return mask==(mask&data_ov031_02290d40[1][0x1a]);
}
