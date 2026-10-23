#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct E;struct Packet{unsigned unknown;unsigned short key,value;unsigned char state,a,b;};
extern "C" {
int Network_GetLocalMemberId(char*);
void* PartySync_GetSharedRecordTable();
GameObject* FieldMonster_FindByPersistentRecordIdentifier(int,int);
E* PartySync_FindEntryByKey(E*,unsigned);
void PartySync_QueueEncounterRejectionAndReset(int,int);
int PartySync_AreAllMemberStatesResolved(char*,int);
bool PartySync_IsSelectedRecordKeyForMember(int,unsigned,int);
int SetIdRecordMemberStateAndPropagateAliases(void*,unsigned,int,int,signed char,unsigned short,unsigned char);
void Object_EmitMatchedTextEntryPacket(unsigned);
}
// Original: arm9/ov017 @ 0x021C5F54; symbol: PartySync_ApplyEncounterResponse; size: 0xE0.
extern "C" void PartySync_ApplyEncounterResponse(int member,Packet* packet,void* unused,unsigned char* resources,char* network){
if(Network_GetLocalMemberId(network)!=0)return;
void* table=PartySync_GetSharedRecordTable();
if(packet->a==0&&packet->b==0&&!FieldMonster_FindByPersistentRecordIdentifier((int)resources,packet->key)&&!PartySync_FindEntryByKey((E*)table,packet->key)){PartySync_QueueEncounterRejectionAndReset(member,packet->key);return;}
if(PartySync_AreAllMemberStatesResolved((char*)table,packet->key))return;
if(PartySync_IsSelectedRecordKeyForMember((int)table,packet->key,member))return;
SetIdRecordMemberStateAndPropagateAliases(table,packet->key,member,packet->state,-1,packet->value,0);
Object_EmitMatchedTextEntryPacket(packet->key);
}
