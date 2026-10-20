#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct Packet{unsigned char opcode,pad[3];unsigned char kind:3;unsigned char count:4;unsigned char spare:1;unsigned char bytes[15];};extern "C" void* Network_GetCommandRecordPool();extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
// Original: arm9/ov017 @ 0x021CCEA4; symbol: QueueByteStreamInFifteenBytePackets; size: 0xCC.
extern "C" void PartySync_QueueSuppliedLearnedSpellList(unsigned kind,const unsigned char* source,int length){Packet packet;void* queue=Network_GetCommandRecordPool();packet.opcode=15;packet.kind=(unsigned char)kind;int offset=0;int block=0;while(offset<length){int i=0;for(;i<15;i++){if(length<=offset+i)break;packet.bytes[i]=source[block*15+i];}packet.count=(unsigned char)i;Network_QueueOutgoingRecord(queue,&packet,0);offset+=packet.count;block++;}}
