#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" void Memory_TransformMD5Block(void*,const void*);
struct HashState {unsigned state[4];unsigned low,high;unsigned char buffer[64];};
// Original: arm9/ov031 @ 0x0220B028; symbol: func_ov031_0220b028; size: 0xB8.
extern "C" void Util_Update64ByteBlockHash(HashState* context,const unsigned char* input,unsigned length) {
unsigned old=context->low;
unsigned index=(old>>3)&63;
context->low=old+(length<<3);
if(context->low<(length<<3)) ++context->high;
unsigned part=64-index;
context->high+=length>>29;
unsigned i;
if(length>=part) {
MI_CpuCopy8(input,context->buffer+index,part);
index=0;
Memory_TransformMD5Block(context,context->buffer);
i=part;
if(i+63<length) do {
Memory_TransformMD5Block(context,input+i);
i+=64;
} while(i+63<length);
} else i=0;
MI_CpuCopy8(input+i,context->buffer+index,length-i);
}
