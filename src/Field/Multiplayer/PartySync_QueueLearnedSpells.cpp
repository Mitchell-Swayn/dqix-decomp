#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Network_GetConnectionManager();extern "C" char* Zone3D_GetMainInstance();extern "C" void* Network_GetCommandRecordPool();extern "C" int Network_IsSessionActive(void*);extern "C" int Network_GetLocalMemberId(void*);extern "C" void* GameResources_GetInstance();extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);extern "C" char* GameState_GetObjectWithFlag100(void*,int);extern "C" void* GameObject_GetLinkedIndexedState(void*);extern "C" int CharacterState_EnumerateLearnedSpells(void*,unsigned char*,int);struct Bits{unsigned char owner:3;unsigned char count:4;unsigned char spare:1;};struct Packet{unsigned char type,pad[3];Bits bits;unsigned char values[15];};
// Original: arm9/ov017 @ 0x021CCDAC; symbol: Network_QueueEnumeratedFlagsInFifteenByteChunks; size: 0xF8.
extern "C" void PartySync_QueueLearnedSpells(int index){char* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);if(!object)return;void* record=GameObject_GetLinkedIndexedState(object);if(!record)return;unsigned char values[66];unsigned char count=CharacterState_EnumerateLearnedSpells(record,values,66);void* pool=Network_GetCommandRecordPool();Packet packet;packet.type=15;packet.bits.owner=(unsigned char)index;int total=0,chunk=0;while(total<count){int size=0;for(;size<15;size++){if(count<=total+size)break;packet.values[size]=values[size+chunk*15];}packet.bits.count=(unsigned char)size;Network_QueueOutgoingRecord(pool,&packet,0);chunk++;total+=packet.bits.count;}}
