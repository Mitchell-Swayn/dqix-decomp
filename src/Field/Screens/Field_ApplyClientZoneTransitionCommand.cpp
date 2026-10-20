#include <globaldefs.h>
#include "GameState/GameState.h"
ARM

extern "C" int Network_GetLocalMemberId(char*);
extern "C" bool LinkedQueue_IsEmpty(const int*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void InitializeTypeFourStateAndBuffers(unsigned char*,int);
extern "C" ARM void FieldEvent_SetPendingContinuationEventId(void*,unsigned short);
extern "C" unsigned int GameState_GetProgressChapter(GameState*);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned*,unsigned);
extern "C" void* GameState_ReadUnkF8(GameState*);
extern "C" ARM void FieldTransition_InitializeRequestDefaults(char*);
extern "C" void* GameState_ReplacePendingFieldTransition(GameState*,const void*);
extern "C" ARM void Field_InitializeZoneTransitionCommand(unsigned char*,int);
extern "C" void Field_QueueArrivalEffect(void*,unsigned char,int);
extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);
// Original: arm9/ov017 @ 0x021D1E50; symbol: func_ov017_021d1e50; size: 0x334.
// Applies connection-controlled transitions within zones1901..1904, including fixed destinations.
extern "C" void Field_ApplyClientZoneTransitionCommand(void*,unsigned char *packet,GameState *game,unsigned char *resources,char *connection){
 char *record;int appendExtra;unsigned short zoneId;unsigned primary;unsigned *queue;
 if(!Network_GetLocalMemberId(connection))return;queue=*(unsigned**)(resources+0x36fc);if(!LinkedQueue_IsEmpty((int*)queue))return;
 unsigned char *zone=(unsigned char*)Zone3D_GetMainInstance();zoneId=*(unsigned short*)zone;
 if(zoneId!=0x1901&&zoneId!=0x1902&&zoneId!=0x1903&&zoneId!=0x1904)return;
 if(*(unsigned short*)(packet+8)||*(unsigned short*)(packet+10)){
 unsigned char *node=*(unsigned char**)(resources+0x3734);InitializeTypeFourStateAndBuffers(node,1);
 primary=*(unsigned short*)(packet+8);unsigned secondary=*(unsigned short*)(packet+10);if(!primary){primary=secondary;secondary=0;}
 *(unsigned short*)(node+8)=primary;FieldEvent_SetPendingContinuationEventId(node,(unsigned short)secondary);
 if((int)GameState_GetProgressChapter(game)>=19&&primary==0x7345&&(unsigned)(zoneId-0x1901)<=3)node[0x105]=1;
 LinkedQueue_AppendAndMarkActive(queue,(unsigned)node);
 }else{
 record=(char*)GameState_ReadUnkF8(game);FieldTransition_InitializeRequestDefaults(record);appendExtra=1;record[7]=1;
 unsigned kind=*(unsigned short*)(packet+4);
 if(kind){
 switch(kind){
 case 1:*(unsigned short*)record=0x1198;*(short*)(record+0x1c)=0;*(int*)(record+0x10)=-0xd000;*(int*)(record+0x14)=0x4333;*(int*)(record+0x18)=-0xd000;appendExtra=0;break;
 case 2:*(unsigned short*)record=0x4e27;*(short*)(record+0x1c)=0;*(int*)(record+0x10)=-0x2b000;*(int*)(record+0x14)=0x14cc;*(int*)(record+0x18)=-0x22000;break;
 case 4:*(unsigned short*)record=0x4e42;*(short*)(record+0x1c)=0;*(int*)(record+0x10)=0x4000;*(int*)(record+0x14)=0x14cc;*(int*)(record+0x18)=0x41000;break;
 case 3:*(unsigned short*)record=0x10cd;*(short*)(record+0x1c)=0x3244;*(int*)(record+0x10)=0;*(int*)(record+0x14)=-0x6ccc;*(int*)(record+0x18)=0;appendExtra=0;break;
 case 5:*(unsigned short*)record=0x1130;*(short*)(record+0x1c)=0x3244;*(int*)(record+0x10)=0;*(int*)(record+0x14)=-0x5ccc;*(int*)(record+0x18)=0x1000;appendExtra=0;break;
 }
 GameState_ReplacePendingFieldTransition(game,record);unsigned char *node=*(unsigned char**)(resources+0x370c);Field_InitializeZoneTransitionCommand(node,0);LinkedQueue_AppendAndMarkActive(queue,(unsigned)node);
 if(appendExtra)Field_QueueArrivalEffect(resources,1,0);
 }else if(*(unsigned short*)(packet+6)){
 record[0x61]=1;*(unsigned short*)record=*(unsigned short*)(packet+6);*(short*)(record+0x1c)=0;*(int*)(record+0x10)=0x100000;*(int*)(record+0x14)=0;*(int*)(record+0x18)=0x100000;
 int pos[3];pos[0]=*(short*)(packet+12)<<7;pos[1]=*(short*)(packet+14)<<7;pos[2]=*(short*)(packet+16)<<7;
 _ZN8Vector3iaSERKS_(zone+0x27b8,pos);
 GameState_ReplacePendingFieldTransition(game,record);unsigned char *node=*(unsigned char**)(resources+0x370c);Field_InitializeZoneTransitionCommand(node,0);LinkedQueue_AppendAndMarkActive(queue,(unsigned)node);
 Field_QueueArrivalEffect(resources,1,0);
 }
 }
}
