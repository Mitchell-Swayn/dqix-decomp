extern "C"
{
    extern unsigned data_ov000_02184294[];
    extern char data_02114e30[];
    int Object_TestNewlySetHalfwordMask(void*,int);
    int TestSelectedRecordReadyAndByteFlagBitOne(void*,int);
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov000 @ 0x0217C594; symbol: func_ov000_0217c594; size: 0x60.
extern "C" bool AdvanceDelayThenTestRecordInput(unsigned char *p,int delay)
{
    if(p[0x956]<delay)
    {
        ++p[0x956];
        return false;
    }
    data_ov000_02184294[2]=(unsigned)p;
    int a=Object_TestNewlySetHalfwordMask(data_02114e30,0x601);
    return (a|TestSelectedRecordReadyAndByteFlagBitOne(p+0x188,20))!=0;
}
