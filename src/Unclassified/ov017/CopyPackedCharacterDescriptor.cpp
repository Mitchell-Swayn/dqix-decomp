// Original: arm9/ov017 @ 0x021D2D00; symbol: func_ov017_021d2d00; size: 0x64.
extern "C" void CopyPackedCharacterDescriptor(unsigned char* d, const unsigned char* s) {
    d[0]=s[0]; d[1]=s[1]; d[2]=s[2]; d[3]=((const signed char*)s)[3];
    d[4]=s[4]; d[5]=s[5]; d[6]=s[6]; d[7]=((const signed char*)s)[7];
    *(unsigned short*)(d+8)=*(const unsigned short*)(s+8);
    *(unsigned short*)(d+10)=*(const unsigned short*)(s+10);
    *(unsigned short*)(d+12)=*(const unsigned short*)(s+12);
    d[14]=((const signed char*)s)[14];
}
