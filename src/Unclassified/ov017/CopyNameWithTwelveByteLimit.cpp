extern "C"
{
    unsigned strlen(const char*);
    char *strcpy(char*,const char*);
    void DisableInterruptsAndHaltForever();
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov017 @ 0x021B2BA0; symbol: func_ov017_021b2ba0; size: 0x30.
extern "C" void CopyNameWithTwelveByteLimit(unsigned char *p,const char *name)
{
    if(strlen(name)>=12)DisableInterruptsAndHaltForever();
    strcpy((char*)p+0x24,name);
}
