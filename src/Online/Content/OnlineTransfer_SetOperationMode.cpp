extern "C"
{
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov031 @ 0x02245528; symbol: func_ov031_02245528; size: 0x20.
extern "C" void OnlineTransfer_SetOperationMode(unsigned char *p,int mode)
{
    p[0x34]=mode;
    p[0x35]=0;
    p[0x37]=0;
    if(!mode)p[0x36]=1;
}
