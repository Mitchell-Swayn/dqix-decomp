#include <globaldefs.h>
ARM
struct PacketRing { unsigned char pad[0x28]; volatile unsigned write; unsigned pad2; volatile unsigned read; unsigned char pad3[0x24]; unsigned char* buffer; volatile unsigned capacity; };
extern "C" PacketRing data_ov031_0224c980;
extern "C" unsigned char data_ov031_0224968c[];
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
// Original: arm9/ov031 @ 0x022008AC; symbol: func_ov031_022008ac; size: 0x1F4.
extern "C" void Network_AppendValidatedFrameToRing(const void* source,const void* destination,const unsigned char* packet,unsigned length,const void* extra,unsigned extraLength) {
 unsigned total; unsigned short size; unsigned next;
 unsigned char* buffer=data_ov031_0224c980.buffer;
 if(!buffer || !data_ov031_0224c980.capacity) return;
 total=length+extraLength;
 if(total<8 || total>0x5e4) return;
 if(packet[0]!=data_ov031_0224968c[0] || packet[1]!=data_ov031_0224968c[1] || packet[2]!=data_ov031_0224968c[2] || packet[6]!=8) return;
 if(packet[7]!=0 && packet[7]!=6) return;
 size=(total+9)&~1;
 next=data_ov031_0224c980.write+size;
 if(data_ov031_0224c980.write<data_ov031_0224c980.read && data_ov031_0224c980.read<=next) return;
 if(next==data_ov031_0224c980.capacity) { next=0; if(data_ov031_0224c980.read==0) return; }
 else if(next>data_ov031_0224c980.capacity) { next=size; if(data_ov031_0224c980.read<=size) return; }
 if(data_ov031_0224c980.write+size>data_ov031_0224c980.capacity) {
  if(data_ov031_0224c980.capacity-data_ov031_0224c980.write>=2) *(unsigned short*)(buffer+data_ov031_0224c980.write)=0;
  data_ov031_0224c980.write=0;
 }
 *(unsigned short*)(data_ov031_0224c980.buffer+data_ov031_0224c980.write)=size;
 MI_CpuCopy8(destination,data_ov031_0224c980.buffer+data_ov031_0224c980.write+2,6);
 MI_CpuCopy8(source,data_ov031_0224c980.buffer+data_ov031_0224c980.write+8,6);
 MI_CpuCopy8(packet+6,data_ov031_0224c980.buffer+data_ov031_0224c980.write+14,length-6);
 if(extra && extraLength) MI_CpuCopy8(extra,data_ov031_0224c980.buffer+data_ov031_0224c980.write+8+length,extraLength);
 data_ov031_0224c980.write=next;
}
