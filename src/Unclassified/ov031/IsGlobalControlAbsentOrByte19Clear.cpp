#pragma optimize_for_size on
extern "C"
{
    extern unsigned char *data_ov031_02250ba8;
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov031 @ 0x02222E54; symbol: func_ov031_02222e54; size: 0x2C.
extern "C" int IsGlobalControlAbsentOrByte19Clear()
{
    unsigned char *p=data_ov031_02250ba8;
    if(!p)return 1;
    if(p[0x19])return 0;
    return 1;
}
