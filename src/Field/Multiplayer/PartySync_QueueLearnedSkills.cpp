#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* GameState_GetObjectWithFlag100(void*,int);extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);extern "C" unsigned CharacterState_EnumerateLearnedSkills(unsigned char*,unsigned short*,unsigned);extern "C" void* Network_GetCommandRecordPool();extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
struct Packet{unsigned char type,pad[3];unsigned char id:3;unsigned char count:3;unsigned char spare:2;unsigned char pad5;unsigned short entries[7];};
// Original: arm9/ov017 @ 0x021CCFD0; symbol: Network_QueueSetBitIndicesInSevenEntryPackets; size: 0x108.
extern "C" void PartySync_QueueLearnedSkills(int index){
char *object=(char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);if(!object)return;unsigned char *data=GameObject_GetLinkedIndexedState(object);if(!data)return;
 unsigned short bits[287];void *connection;int consumed;int chunk;int count;count=(unsigned short)CharacterState_EnumerateLearnedSkills(data,bits,287);connection=Network_GetCommandRecordPool();Packet packet;packet.type=16;packet.id=(unsigned char)index;
 consumed=0;chunk=0;for(;consumed<count;++chunk){int i=0;for(;i<7;++i){if(count<=consumed+i)break;packet.entries[i]=bits[chunk*7+i];}packet.count=(unsigned char)i;Network_QueueOutgoingRecord(connection,&packet,0);consumed+=packet.count;}

}
