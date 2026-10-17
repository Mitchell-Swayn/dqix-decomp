#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02291a04[];
extern "C" void Memory_CopyBytesToDestination(void*,const void*,unsigned int);
extern "C" int OV031_TranslateOperationError(unsigned char*,int,const void*,int,int);
// Original: arm9/ov031 @ 0x022415E0; symbol: func_ov031_022415e0; size: 0xB4.
extern "C" int Object_BufferBytesAndFlushFullBlocks(unsigned char* context,int handle,int* buffered,const unsigned char* source,int length) {
int remaining=length;
if(remaining>0)do {
if(*(int*)(context+4))return -1;
int size=0x400-*buffered;
if(remaining<=size)size=remaining;
Memory_CopyBytesToDestination(data_ov031_02291a04+*buffered,source,size);
*buffered+=size;source+=size;remaining-=size;
if(*buffered==0x400){int result=OV031_TranslateOperationError(context,handle,data_ov031_02291a04,0x400,0);if(result<=0)return result;*buffered-=result;}
}while(remaining>0);
return length;
}
