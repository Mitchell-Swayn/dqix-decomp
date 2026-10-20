#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Network_GetConnectionManager();extern "C" char* Zone3D_GetMainInstance();extern "C" void* Network_GetCommandRecordPool();extern "C" int Network_IsSessionActive(void*);extern "C" int Network_GetLocalMemberId(void*);extern "C" void* GameResources_GetInstance();extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);extern "C" void* GameState_ReadUnkF8(void*);struct Vec{int x,y,z;};struct Packed{unsigned char type,pad[3];short id;signed short key:14;signed short mode:2;short x,y,z,heading;unsigned char value;};
// Original: arm9/ov017 @ 0x021D1A18; symbol: Network_QueuePackedPositionAndHeading; size: 0xF8.
extern "C" void Network_QueueHostZonePositionAndHeading(short id,short key,short mode,unsigned char value){if(!Network_IsSessionActive(Network_GetConnectionManager()))return;if(Network_GetLocalMemberId(Network_GetConnectionManager())!=0)return;GameResources_GetInstance();GameState_ReadUnkF8(_ZN9GameState11GetInstanceEv());char* zone=Zone3D_GetMainInstance();void* pool=Network_GetCommandRecordPool();Packed packet;packet.type=178;if(!id)id=1;packet.id=id;packet.key=key;packet.mode=mode;Vec position=*(Vec*)(zone+0x2774);packet.x=position.x>>7;packet.y=position.y>>7;packet.z=position.z>>7;packet.heading=W(zone,0x2780);packet.value=value;Network_QueueOutgoingRecord(pool,&packet,0);}
