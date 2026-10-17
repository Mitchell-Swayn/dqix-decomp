#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
extern "C" char data_ov023_021ff9e0[];
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/ov023 @ 0x021DDC34; symbol: func_ov023_021ddc34; size: 0x64.
extern "C" int AttachSharedBufferAndSetFourHalfwords(char* obj,short a,short b,short c,short d) {
    char* buffer=*(char**)(data_ov023_021ff9e0+4);
    int result=0;
    if(buffer && obj) {
        memset(buffer,0,0x1800);
        *(char**)(obj+8)=*(char**)(data_ov023_021ff9e0+4);
        *(short*)(obj+0xac)=a;
        *(short*)(obj+0xae)=b;
        *(short*)(obj+0xa8)=c;
        *(short*)(obj+0xaa)=d;
        result=1;
    }
    return result;
}
