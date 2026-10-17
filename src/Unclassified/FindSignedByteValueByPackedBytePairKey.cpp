#include <globaldefs.h>
ARM
extern "C" unsigned char* data_0210782c[];
// Original: arm9/main @ 0x020425E4; symbol: func_020425e4; size: 0x54.
extern "C" int FindSignedByteValueByPackedBytePairKey(unsigned int a,unsigned int b,int table) { unsigned char* p=data_0210782c[table];unsigned short key=(a&255)|((b&255)<<8);unsigned int count=*(unsigned int*)(p+8);unsigned char* entry=*(unsigned char**)(p+12);for(unsigned int i=0;i<count;entry+=4,i++)if(*(unsigned short*)entry==key)return *(signed char*)(entry+2);return 0; }
