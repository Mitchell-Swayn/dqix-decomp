#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
// Queue records have 16 halfword entries and a trailing word, stride 36.
// Original: arm9/main @ 0x020D2A48; symbol: func_020d2a48; size: 0x7C.
extern "C" ARM void Initialize640ByteTableWithIndexSentinelsAndFlush(char* p){int i=0;int j;*(int*)(p+4)=0;*(short*)(p+8)=0;*(short*)(p+10)=0;*(int*)p=0;int* row=(int*)p;do{row[16]=0;j=0;do{*(short*)((char*)row+32+j*2)=-1;j++;}while(j<16);i++;row+=9;}while(i<16);int k=0;do{*(short*)(p+608+k*2)=-1;k++;}while(k<16);_Z25CleanInvalidateCacheRangePKvj(p,640);}
