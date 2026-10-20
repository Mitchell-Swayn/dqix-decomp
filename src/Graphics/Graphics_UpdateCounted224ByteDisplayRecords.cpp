#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void TextCanvas_ResetLayoutAndDisplayFlags(char*);
// Original: arm9/main @ 0x0207FE44; symbol: func_0207fe44; size: 0x3C.
extern "C" void Graphics_UpdateCounted224ByteDisplayRecords(char* p){
    unsigned char count;
    char* entry=*(char**)(p+0x30);
    if(!entry)return;
    count=p[0x39];
    for(unsigned char i=0;i<count;++i){TextCanvas_ResetLayoutAndDisplayFlags(entry);entry+=0xe0;}
}
