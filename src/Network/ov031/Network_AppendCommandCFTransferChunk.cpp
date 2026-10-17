#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
struct Transfer {int pad[3];unsigned char* buffer;int pad2;unsigned limit,offset;int pad3;int complete;unsigned finalSize;};
struct Owner {int pad[9];Transfer* transfer;};
extern "C" Owner* data_ov031_0224e580;
// Original: arm9/ov031 @ 0x0220F770; symbol: func_ov031_0220f770; size: 0xA4.
extern "C" int Network_AppendCommandCFTransferChunk(unsigned char* record){
 int result=1;
 if(*(int*)(record+8)==0xcf){
 unsigned offset;
 unsigned count=*(unsigned*)(record+0x10);
 Transfer* t=data_ov031_0224e580->transfer;
 offset=t->offset;
 unsigned char* buffer=t->buffer;
 if(t->limit<offset+count)count=t->limit-offset;
 if(buffer)MI_CpuCopy8(record+0x14,buffer+offset,count);
 unsigned end=offset+count;
 data_ov031_0224e580->transfer->offset=end;
 if(*(int*)(record+0xc))result=0;
 else{
 data_ov031_0224e580->transfer->finalSize=end;
 data_ov031_0224e580->transfer->complete=1;
 }
 }
 return result;
}
