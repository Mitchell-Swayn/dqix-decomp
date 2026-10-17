#include <globaldefs.h>
ARM
struct HashState { unsigned digest[5]; unsigned low,high,used; unsigned char buffer[64]; };
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" void (*data_020f2154)(HashState*,const void*,unsigned);
// Original: arm9/main @ 0x020C08EC; symbol: func_020c08ec; size: 0x154.
extern "C" void Hash_Update64ByteBlocks(HashState* state,const unsigned char* data,unsigned size) {
 unsigned char* buffer=state->buffer;
 if(!size)return;
 unsigned low=state->low+(size<<3);
 if(low<state->low)state->high++;
 state->high+=size>>29;
 state->low=low;
 if(state->used) {
 if(state->used+size>=64) {
 unsigned fill=64-state->used;
 MI_CpuCopy8(data,buffer+state->used,fill);
 size-=fill;data+=fill;
 data_020f2154(state,buffer,64);
 state->used=0;
 } else {
 MI_CpuCopy8(data,buffer+state->used,size);
 state->used+=size;
 return;
 }
 }
 if(size>=64) {
 int blocks=size&~63;
 size-=blocks;
 if(!((unsigned)data&3)) {
 data_020f2154(state,data,blocks);
 data+=blocks;
 } else {
 do {
 MI_CpuCopy8(data,buffer,64);
 data+=64;
 data_020f2154(state,buffer,64);
 blocks-=64;
 }while(blocks>0);
 }
 }
 state->used=size;
 if(size)MI_CpuCopy8(data,buffer,size);
}
