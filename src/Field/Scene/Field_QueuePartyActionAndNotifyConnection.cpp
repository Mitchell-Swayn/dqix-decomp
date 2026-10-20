#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
struct Triple{int x,y,z;};extern "C" char* _ZN9GameState11GetInstanceEv();extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);extern "C" void Field_SetPartyActionPosition(void*,int,int,int);extern "C" void InitializeObjectSentinelAndType42(void*);extern "C" void LinkedQueue_AppendAndMarkActive(void*,void*);extern "C" void* Network_GetConnectionManager();extern "C" bool Network_IsParentOrOffline(void*);extern "C" unsigned short* Zone3D_GetMainInstance();extern "C" void QueueTag27ForPositiveIdWhenStateInactive(int,unsigned short);
// Original: arm9/ov017 @ 0x021913D0; symbol: QueuePositiveRecordAndNotifyConnection; size: 0xb4.
extern "C" void Field_QueuePartyActionAndNotifyConnection(char* self,int id){
if(id<=0)return;char* record=P(self,0x3ba0);if(!B(record,2)){if(!B(record,11)){char* state=_ZN9GameState11GetInstanceEv();Triple point=*(Triple*)(_ZN9GameState21GetPartyMemberByIndexEi(state,0)+0x44);Field_SetPartyActionPosition(state+0x7f60,point.x,point.y,point.z);}InitializeObjectSentinelAndType42(record);B(record,11)=id;LinkedQueue_AppendAndMarkActive(P(self,0x3700),record);}if(Network_IsParentOrOffline(Network_GetConnectionManager()))QueueTag27ForPositiveIdWhenStateInactive(id,*Zone3D_GetMainInstance());
}
