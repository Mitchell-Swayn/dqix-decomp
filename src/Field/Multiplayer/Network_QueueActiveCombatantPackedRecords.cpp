#include <globaldefs.h>
ARM
struct GameResources;
struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" void* Network_GetCommandRecordPool();
extern "C" unsigned int PartySelection_GetMemberMask(unsigned char*,unsigned int);
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct Payload { unsigned short id,index; unsigned a:3,b:3,c:3,d:3,e:3,f:3,g:3,h:3,i:3,j:3; unsigned k:3,l:3,m:3,n:3,o:3,p:3,q:3,r:3,s:3,t:3; unsigned short unknown; unsigned char flag; };
// Original: arm9/ov017 @ 0x021C7484; symbol: func_ov017_021c7484; size: 0x3F8.
extern "C" void Network_QueueActiveCombatantPackedRecords() {
void* gs=_ZN9GameState11GetInstanceEv();
unsigned char* state=(unsigned char*)FieldBattle_GetEncounterRequest(*(void**)((unsigned char*)GameResources_GetInstance()+0x3718));
Object* queue=(Object*)Network_GetCommandRecordPool();
unsigned char record[20];
record[0]=0x72;
Payload* payload=(Payload*)(record+4);
for(int i=0;i<4;i++) {
if(PartySelection_GetMemberMask(state,(unsigned char)i)) {
unsigned char* obj=(unsigned char*)_ZN9GameState19GetCombatantByIndexEi(gs,i);
if((*(unsigned char**)(obj+0x138))[0x26]) {
payload->id=*(unsigned short*)(state+8);
payload->index=i;
unsigned char* data=*(unsigned char**)(obj+0x138);
payload->flag=1;
payload->a=data[0x5c];
payload->b=data[0x5d];
payload->c=data[0x5e];
payload->d=data[0x5f];
payload->e=data[0x60];
payload->f=data[0x61];
payload->g=data[0x62];
payload->h=data[0x63];
payload->i=data[0x64];
payload->j=data[0x65];
payload->k=data[0x66];
payload->l=data[0x67];
payload->m=data[0x68];
payload->n=data[0x69];
payload->o=data[0x6a];
payload->p=data[0x6b];
payload->q=data[0x6c];
payload->r=data[0x6d];
payload->s=data[0x6e];
payload->t=data[0x6f];
Network_QueueOutgoingRecord(queue,record,0);
data=*(unsigned char**)(obj+0x138);
payload->flag=0;
payload->a=data[0x7f];
payload->b=data[0x80];
payload->c=data[0x81];
payload->d=data[0x82];
payload->e=data[0x83];
payload->f=data[0x84];
payload->g=data[0x85];
payload->h=data[0x86];
payload->i=data[0x87];
payload->j=data[0x88];
payload->k=data[0x89];
payload->l=data[0x8a];
payload->m=data[0x8b];
payload->n=data[0x8c];
payload->o=data[0x8d];
payload->p=data[0x8e];
payload->q=data[0x8f];
payload->r=data[0x90];
payload->s=data[0x91];
payload->t=data[0x92];
Network_QueueOutgoingRecord(queue,record,0);
}
}
}
}
