// Original: arm9/ov025 @ 0x021ecb90; symbol: func_ov025_021ecb90; size: 0xc4.
extern "C" void CopyPackedRecordFields(unsigned char* d,const unsigned char* s) {
    *(unsigned*)d=*(const unsigned*)s;
    d[4]=s[4]; d[5]=s[5]; d[6]=s[6];
    *(unsigned*)(d+8)=*(const unsigned*)(s+8); *(unsigned*)(d+0xc)=*(const unsigned*)(s+0xc);
    *(unsigned*)(d+0x10)=*(const unsigned*)(s+0x10); *(unsigned*)(d+0x14)=*(const unsigned*)(s+0x14);
    *(unsigned*)(d+0x18)=*(const unsigned*)(s+0x18); *(unsigned*)(d+0x1c)=*(const unsigned*)(s+0x1c);
    *(short*)(d+0x20)=*(const short*)(s+0x20); *(short*)(d+0x22)=*(const short*)(s+0x22);
    *(unsigned*)(d+0x24)=*(const unsigned*)(s+0x24); *(unsigned*)(d+0x28)=*(const unsigned*)(s+0x28);
    *(unsigned short*)(d+0x2c)=*(const unsigned short*)(s+0x2c); *(unsigned short*)(d+0x2e)=*(const unsigned short*)(s+0x2e);
    *(unsigned short*)(d+0x30)=*(const unsigned short*)(s+0x30); *(unsigned short*)(d+0x32)=*(const unsigned short*)(s+0x32);
    *(unsigned short*)(d+0x34)=*(const unsigned short*)(s+0x34); *(unsigned short*)(d+0x36)=*(const unsigned short*)(s+0x36);
    d[0x38]=s[0x38]; d[0x39]=s[0x39]; d[0x3a]=s[0x3a]; *(unsigned short*)(d+0x3c)=*(const unsigned short*)(s+0x3c);
}
