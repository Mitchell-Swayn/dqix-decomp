#include <globaldefs.h>
ARM
struct Payload {char pad[4];unsigned char flags;unsigned char index:4;unsigned char expected:4;unsigned short value,alternate;};
extern "C" {void* GameState_GetObjectWithFlag100(void*,int);int Network_GetLocalMemberId(char*);void _ZN8Object3D10SetField06Et(void*,unsigned short);unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);void* FieldBattle_GetEncounterRequest(void*);}
// Original: arm9/ov017 @ 0x021C435C; symbol: func_ov017_021c435c; size: 0xBC.
extern "C" void ApplyRemoteIndexedObjectField(void* unused,Payload* payload,void* game,char* owner,char* connection){
if(payload->flags&1){if(Network_GetLocalMemberId(connection)!=payload->expected)return;}
int index=payload->index;
if(index==Network_GetLocalMemberId(connection))return;
char* object=(char*)GameState_GetObjectWithFlag100(game,index);if(!object)return;
unsigned short value=payload->value;
if(payload->flags&2)value=payload->alternate;
unsigned char* state=*(unsigned char**)(owner+0x3718);
unsigned char* flags=(unsigned char*)FieldBattle_GetEncounterRequest(state);
if(state[2]){if(PartySelection_GetMemberMask(flags,payload->index)){*(unsigned*)(object+0x15c)=value;return;}}
_ZN8Object3D10SetField06Et(object,value);
}
