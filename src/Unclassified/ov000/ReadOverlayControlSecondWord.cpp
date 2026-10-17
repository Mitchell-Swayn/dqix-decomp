extern "C"
{
    extern unsigned data_ov000_02184220[];
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov000 @ 0x02160130; symbol: func_ov000_02160130; size: 0x10.
extern "C" unsigned ReadOverlayControlSecondWord()
{
    return data_ov000_02184220[1];
}
