#include <globaldefs.h>
ARM
extern "C" unsigned char* data_ov031_0224e5d8;
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
// Original: arm9/ov031 @ 0x022161B0; symbol: func_ov031_022161b0; size: 0x9C.
extern "C" int CopyReadyIndexedByteRecord(int index,unsigned char* out) {
 unsigned char* self=data_ov031_0224e5d8;
 if(*(int*)(self+0x1a90)!=2) return -1;
 if(index<0 || index>=*(int*)(self+0x1a88)) return -1;
 VectorizedMemset(out,0,0x78);
 *(unsigned*)out=1;
 *(unsigned short*)(out+4)=*(unsigned short*)(data_ov031_0224e5d8+index*2+0x1a48);
 MI_CpuCopy8(data_ov031_0224e5d8+0x1348+index*0x70,out+6,0x70);
 return 0;
}
