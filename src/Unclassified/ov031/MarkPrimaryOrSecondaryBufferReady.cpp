extern "C"
{
    extern unsigned char *data_ov031_02290d38;
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov031 @ 0x0223CAEC; symbol: func_ov031_0223caec; size: 0x24.
extern "C" void MarkPrimaryOrSecondaryBufferReady(void *p)
{
    unsigned char *q=data_ov031_02290d38;
    if(p==q+0x610)q[0x67c]=1;
    else q[0x67d]=1;
}
