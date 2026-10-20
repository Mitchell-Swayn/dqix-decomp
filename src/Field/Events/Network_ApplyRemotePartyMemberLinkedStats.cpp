#include <globaldefs.h>
ARM
extern "C" int GameState_GetIndexList(...);
extern "C" int GameState_GetObjectWithFlag100(...);
extern "C" void GameObject_SetLinkedStatAndMarkChanged(char*,int,short);
extern "C" int Field_QueuePartyMemberEquipmentRefresh(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021C40EC; symbol: ApplyFiveRemoteStatChangesUnlessMemberExcluded.
extern "C" void Network_ApplyRemotePartyMemberLinkedStats(int unused,char*packet,int state,char*resources){
struct Flags{unsigned char index:4;unsigned char apply:1;unsigned char spare:3;};unsigned index=((Flags*)(packet+4))->index;char*list=C(GameState_GetIndexList(state));if(list){for(int i=0;i<B(list,0xf7c);i++)if(index==B(list+i,0xf78))return;}char*object=C(GameState_GetObjectWithFlag100(state,index));if(!object)return;char*context=P(resources+0x3000,0x734);for(int i=0;i<5;i++){int stat=*(signed char*)(packet+i+5);unsigned value=S(packet+i*2,10);if(stat>=0&&stat<10)GameObject_SetLinkedStatAndMarkChanged(object,stat,(short)value);if(B(context,3)&&index==0&&stat==6){if(*(signed char*)(context+0x180)<0)B(context,0x180)=6;}}if(((Flags*)(packet+4))->apply)Field_QueuePartyMemberEquipmentRefresh(resources,index,0,0,0);
}
