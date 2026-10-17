#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0203C6FC; symbol: func_0203c6fc; size: 0x40.
extern "C" void DecrementIndexedReferenceAndActiveRecordCount(unsigned char* p,int index){if(index<0)return;unsigned char* entry=p+4+(short)index*40;if(!entry[36])return;int count=entry[36]-1;entry[36]=count;if(!(count&255))--*(unsigned short*)(p+0x512);}
