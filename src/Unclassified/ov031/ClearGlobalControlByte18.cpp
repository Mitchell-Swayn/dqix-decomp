extern "C"
{
    extern unsigned char *data_ov031_02250ba8;
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov031 @ 0x02222E80; symbol: func_ov031_02222e80; size: 0x18.
extern "C" void ClearGlobalControlByte18()
{
    data_ov031_02250ba8[0x18]=0;
}
