#include <globaldefs.h>
ARM
#pragma opt_propagation off
#include <std_library_functions.h>
extern "C" unsigned long long Unclassified_AccumulateBytesModuloConstant(int,const unsigned char*);
extern "C" void RC4_InitializeKeySchedule(void*,const char*,unsigned);
extern "C" void RC4_TransformBytes(void*,void*,int,void*);
extern "C" char OnlineContent_DecryptInfoPayload_TextXENLONPROJECTKEY[];
// Original: arm9/ov023 @ 0x021F5CD8; symbol: TransformZeroChecksumBufferAndCopyPayload; size: 0x80.
extern "C" int OnlineContent_DecryptInfoPayload(unsigned char* bytes,int count,void* output){
char state[260];if(Unclassified_AccumulateBytesModuloConstant(count,bytes)!=0)return 0;char* seed=OnlineContent_DecryptInfoPayload_TextXENLONPROJECTKEY;RC4_InitializeKeySchedule(state,seed,strlen(seed));RC4_TransformBytes(state,bytes,count-4,output);memcpy(bytes,output,count-4);return 1;
}
