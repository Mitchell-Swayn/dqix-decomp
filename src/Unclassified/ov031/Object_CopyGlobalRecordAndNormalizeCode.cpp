#include <globaldefs.h>
#include <System/Memory.h>
ARM
extern "C" unsigned char data_ov031_0224e5e8[];
// Original: arm9/ov031 @ 0x02216B00; symbol: func_ov031_02216b00; size: 0x90.
extern "C" void Object_CopyGlobalRecordAndNormalizeCode(unsigned char* output) {
if(!*(void**)(data_ov031_0224e5e8+8))VectorizedMemset(output,0,0x1c4);
MI_CpuCopy8(*(unsigned char**)(data_ov031_0224e5e8+8)+0x1008,output,0x1c4);
int code=*(int*)output;
if(code<20000 || code>=30000)*(int*)output=0x5206;
if(*(int*)output>=20100)*(int*)output=-*(int*)output;
}
