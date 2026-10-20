#include <globaldefs.h>
ARM
extern "C" unsigned char* DisplayLayout_FindPartById(void*,int);
// Original: arm9/main @ 0x02081058; symbol: func_02081058; size: 0x34.
extern "C" void TextCanvas_EnableEntryMarkupWithControlByte(unsigned char* p,int key,int value){unsigned char* q=DisplayLayout_FindPartById(p+4,key);if(!q)return;q[43]=value;q[44]=8;q[42]|=32;}
