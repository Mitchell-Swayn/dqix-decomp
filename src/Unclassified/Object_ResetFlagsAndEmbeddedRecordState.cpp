#include <globaldefs.h>
struct Reset {unsigned short a,flags,b,c;unsigned d;unsigned char e; signed char f;char rest[0x30e];};
extern "C" void InitializeRecordWithField20Enabled(void*);
extern "C" void ClearHalfwordAtOffset18(void*);
extern "C" void ClearMemoryRange192(void*);
extern "C" void Clear456ByteBufferAndInitializeTrailingWords(void*);
extern "C" void Object_Clear12Bytes(void*);
extern "C" void ClearOutputWordAndByte(void*);
extern "C" void ClearTwelveBytes_Main020A8E88(void*);
// Original: arm9/main @ 0x020289C4; symbol: func_020289c4; size: 0x90.
extern "C" void Object_ResetFlagsAndEmbeddedRecordState(Reset* p) {unsigned mask=0xffff000f;p->flags&=~4;p->flags&=~8;p->a=0;p->d=0;p->c=0;p->e=0;p->flags&=mask;p->b=0;p->f=(int)mask>>16;InitializeRecordWithField20Enabled((char*)p+0x18);ClearHalfwordAtOffset18((char*)p+0x44);ClearMemoryRange192((char*)p+0x60);Clear456ByteBufferAndInitializeTrailingWords((char*)p+0x124);Object_Clear12Bytes((char*)p+0x2f8);ClearOutputWordAndByte((char*)p+0x304);ClearTwelveBytes_Main020A8E88((char*)p+0x30c);}
