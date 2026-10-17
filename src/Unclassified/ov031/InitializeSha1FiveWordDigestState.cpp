extern "C"
{
    void VectorizedMemset(void*,int,unsigned);
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov031 @ 0x0220B8A0; symbol: func_ov031_0220b8a0; size: 0x54.
extern "C" void InitializeSha1FiveWordDigestState(unsigned *p)
{
    VectorizedMemset(p,0,0x5c);
    p[0]=0x67452301;
    p[1]=0xefcdab89;
    p[2]=0x98badcfe;
    p[3]=0x10325476;
    p[4]=0xc3d2e1f0;
}
