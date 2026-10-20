#include <globaldefs.h>
ARM
extern "C" int Network_GetLocalMemberId(char*);
extern "C" void* FieldMonster_SpawnInFrontOfPartyMember(void*,int,int,int);
extern "C" void QueueHalfwordByteAndTwoWordCommand(void*,int,int,int);
// Original: arm9/ov017 @ 0x021D0A18; symbol: UpdatePrimaryIndexedRecordOrDispatchObject; size: 0x90.
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" void FieldNetwork_ApplyMonsterCallResultOrSpawnRequest(int index,char* record,int unused,char* self,char* indexed) {
 if(Network_IsParentOrOffline((unsigned*)indexed)) {void *p=FieldMonster_SpawnInFrontOfPartyMember(self,index,*(int*)(record+8),*(int*)(record+12));QueueHalfwordByteAndTwoWordCommand(p,index,0,*(int*)(record+12));return;}
 if(index)return;
 if(*(unsigned char*)(record+6)!=Network_GetLocalMemberId(indexed))return;
 char *target=*(char**)(self+0x3bac);
 if(*(unsigned short*)(record+4)){target[16]=5;*(unsigned short*)(target+18)=*(unsigned short*)(record+4);}else target[16]=2;
}
