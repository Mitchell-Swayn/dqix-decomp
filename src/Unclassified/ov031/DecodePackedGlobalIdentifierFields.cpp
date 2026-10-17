extern "C"
{
    void MI_CpuCopy8(const void*,void*,unsigned);
    extern unsigned char data_ov031_0224e6ac[],data_ov031_0224e6b1[],data_ov031_0224e6b6[],data_ov031_0224e6b8[];
    struct Fields
    {
        unsigned long long a,b;
        unsigned short c,d;
    };
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov031 @ 0x0221AE00; symbol: func_ov031_0221ae00; size: 0xD8.
extern "C" void DecodePackedGlobalIdentifierFields(Fields *p)
{
    MI_CpuCopy8(data_ov031_0224e6ac,&p->a,6);
    p->a &= 0x7ffffffffffULL;
    MI_CpuCopy8(data_ov031_0224e6b1,&p->b,6);
    p->b >>=3;
    p->b &=0x7ffffffffffULL;
    MI_CpuCopy8(data_ov031_0224e6b6,&p->c,2);
    p->c >>=6;
    p->c &=0x3ff;
    MI_CpuCopy8(data_ov031_0224e6b8,&p->d,2);
}
