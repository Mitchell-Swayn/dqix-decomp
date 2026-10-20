#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02205C50; symbol: func_ov031_02205c50; size: 0x74.
// Reads remaining timed-record length and metadata; returns the current data pointer for nonempty or state-four records.
extern "C" void* Network_GetSocketReceiveSpan(void* self,int* remaining,unsigned short* first,unsigned short* second,unsigned* word)
{
    char* context=*(char**)((char*)self+0x64);
    char* record=*(char**)(context+0xc4);
    int offset=*(int*)(context+0xf8);
    int length=*(int*)(record+0x44)-offset;
    if(length>=0) {
        *first=*(unsigned short*)(record+0xa);
        *second=*(unsigned short*)(record+0x18);
        *word=*(unsigned*)(record+0x1c);
        *remaining=length;
        if(length==0 && *(unsigned char*)(record+8)!=4)return 0;
    } else { *remaining=-1;return 0; }
    return *(char**)(record+0x40)+offset;
}
