#include <globaldefs.h>
ARM
extern "C" char* Network_GetCommandRecordPool(...);
extern "C" void Network_QueueOutgoingRecord(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};
// Original: arm9/ov017 @ 0x021CD0D8; symbol: Network_QueueHalfwordListInSevenEntryChunks; size: 0xd4.
// Queues type16 records containing up to seven halfwords and packed three-bit index/count fields.
extern "C" void Network_QueueHalfwordListInSevenEntryChunks(int index,unsigned short* input,int count){char* owner=Network_GetCommandRecordPool();struct Packet {unsigned char type;char pad[3];unsigned char index:3;unsigned char count:3;unsigned char unused:2;char pad2;unsigned short values[7];};Packet packet;packet.type=16;packet.index=(unsigned char)index;int done=0;int chunk=0;while(done<count){int n=0;for(;n<7;++n){if(count<=done+n)break;packet.values[n]=input[n+7*chunk];}packet.count=(unsigned char)n;Network_QueueOutgoingRecord(owner,&packet,0);++chunk;done+=packet.count;}}
