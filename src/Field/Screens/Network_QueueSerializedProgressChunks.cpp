#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" char* _ZN9GameState14GetProtagonistEv(void*);extern "C" void* Network_GetConnectionManager();extern "C" int Network_IsParentOrOffline(void*);extern "C" char* Zone3D_GetMainInstance();extern "C" char* GameState_GetSerializedProgressState();extern "C" char* Network_GetCommandRecordPool();extern "C" char* GameResources_GetInstance();extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);struct Chunk{unsigned char bytes[14];unsigned short size:4;unsigned short mode:2;unsigned short index:10;};struct Packet{unsigned char type;unsigned char pad[3];Chunk chunk;};
// Original: arm9/ov017 @ 0x021D2184; symbol: Network_QueueFourteenByteRecordChunks; size: 0xF4.
extern "C" void Network_QueueSerializedProgressChunks(unsigned short mode){if(Network_IsParentOrOffline(Network_GetConnectionManager())){void* pool=Network_GetCommandRecordPool();Packet packet;packet.type=156;Chunk* chunk=&packet.chunk;chunk->mode=mode;char* source=GameState_GetSerializedProgressState()+0x2cc;int remaining=102;unsigned char index=0;for(;remaining>0;){if(remaining>14)chunk->size=14;else chunk->size=(unsigned short)remaining;chunk->index=index;memcpy(chunk,source,chunk->size);Network_QueueOutgoingRecord(pool,&packet,0);unsigned next=index+1;source+=14;remaining-=14;index=next;}}}
