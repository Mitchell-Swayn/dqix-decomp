#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" int ReadIndexedSignedField1038(char*);
extern "C" void AppendTypedBufferChunk(void*,const void*,unsigned,unsigned,unsigned);
struct Flags12 { unsigned char channel:2,mode:2,rest:4; };
struct Flags13 { unsigned char operation:2,length:4,finish:1,special:1; };
struct Packet { unsigned word; unsigned char data[14]; Flags12 a; Flags13 b; };
struct Key6 { unsigned char value[6]; };
struct Row { Key6 key; signed char source; unsigned char active,length; signed char slot; };
struct ActiveFlag { unsigned short pad:14,active:1,top:1; };
struct Buffer { Key6 key; unsigned char pad[12]; ActiveFlag flags; unsigned char data[24]; };
// Original: arm9/ov017 @ 0x021D15B0; symbol: func_ov017_021d15b0; size: 0x260.
extern "C" void Network_ProcessKeyedPacketFragments(int source,Packet* packet,char* state,char* owner,char* settings) {
 void* target=*(void**)(owner+0x3b84);
 int channel=ReadIndexedSignedField1038(settings);
 if(!packet->b.special) {
 if(channel==packet->a.channel) AppendTypedBufferChunk(target,packet->data,packet->b.operation,packet->b.length,packet->b.finish);
 return;
 }
 if(packet->b.operation==2) {
 if(packet->a.mode!=1) return;
 Row* row=(Row*)(state+0x74c0);
 for(int i=0;i<3;i++,row++) {
 if(row->source==source) return;
 if(row->source<0) {memcpy(row,packet->data,packet->b.length);row->source=source;return;}
 }
 return;
 }
 if(packet->b.operation!=0) return;
 if(packet->a.mode==0 && channel!=packet->a.channel) return;
 Row* row=(Row*)(state+0x74c0);
 for(int i=0;i<3;i++,row++) {
 if(row->source!=source) continue;
 if(row->slot<0) {
 Buffer* buffer=(Buffer*)(state+0x7200);
 int j=0;
 for(;j<16;j++,buffer++) {
 if(buffer->flags.active) {
 Key6 key=row->key;
 int equal;
 for(int k=0;k<6;k++) if(key.value[k]!=buffer->key.value[k]) {equal=0;goto compared;}
 equal=1;
 compared:
 if(equal) {row->slot=j;row->active=1;break;}
 }
 }
 if(j==16) return;
 }
 memcpy(((Buffer*)(state+0x7200))[row->slot].data+row->length,packet->data,packet->b.length);
 row->length+=packet->b.length;
 if(packet->b.finish) {row->active=0;row->length=0;row->slot=-1;}
 break;
 }
}
