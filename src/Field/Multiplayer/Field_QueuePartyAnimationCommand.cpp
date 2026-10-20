#include <globaldefs.h>
ARM
struct GameState;struct Object;
struct Payload {unsigned char a,b;unsigned char low:4;unsigned char high:4;unsigned char index;unsigned value;};
struct Message {unsigned char kind;char pad[3];Payload data;char tail[8];};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadFirstObjectIndex(GameState*);
extern "C" void* Network_GetConnectionManager();
extern "C" void* Network_GetCommandRecordPool();
extern "C" unsigned Network_TestMemberDisconnectFlag(char*,int);
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
// Original: arm9/ov017 @ 0x021D3F00; symbol: func_ov017_021d3f00; size: 0xA8.
extern "C" void Field_QueuePartyAnimationCommand(const unsigned char* object,unsigned char a,unsigned char b) {
if(!object) return;
GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
if(Network_TestMemberDisconnectFlag((char*)Network_GetConnectionManager(),0)) return;
Object* connection=(Object*)Network_GetCommandRecordPool();
Message message;
Payload* payload=&message.data;
message.kind=0x3b;
payload->a=object[1];
payload->b=object[3];
payload->low=a;
payload->high=b;
payload->value=*(const unsigned*)(object+0x48);
payload->index=GameState_ReadFirstObjectIndex(state);
Network_QueueOutgoingRecord(connection,&message,0);
}
