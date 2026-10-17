#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void InitializeRecordWithField20Enabled(char*);
extern "C" void ClearHalfwordAtOffset18(char*);
extern "C" void ClearMemoryRange192(char*);
extern "C" void Clear456ByteBufferAndInitializeTrailingWords(char*);
extern "C" void Object_Clear12Bytes(char*);
extern "C" void ClearOutputWordAndByte(char*);
extern "C" void ClearTwelveBytes_Main020A8E88(char*);
// Original: arm9/main @ 0x020287B4; symbol: func_020287b4; size: 0xE0.
extern "C" void Object_InitializeFour318ByteRecords(char* base){
    for(int i=0;i<4;++i){
        char* p=base+i*0x318;
        volatile unsigned short* flags=(volatile unsigned short*)(p+2);
        *flags &= ~4;*flags &= ~8;*flags &= ~3;
        *(unsigned short*)(base+i*0x318)=0;
        *(unsigned*)(p+16)=0;*(unsigned*)(p+20)=0;*(unsigned*)(p+8)=0;
        *(unsigned short*)(p+6)=0;p[12]=0;
        *flags &= 0xffff000f;
        *(unsigned short*)(p+4)=0;p[13]=-1;
        InitializeRecordWithField20Enabled(p+24);ClearHalfwordAtOffset18(p+0x44);ClearMemoryRange192(p+0x60);
        Clear456ByteBufferAndInitializeTrailingWords(p+0x124);Object_Clear12Bytes(p+0x2f8);ClearOutputWordAndByte(p+0x304);ClearTwelveBytes_Main020A8E88(p+0x30c);
        *flags=(*flags&~3)|((unsigned short)i&3);
    }
}
