#include <globaldefs.h>
#include "GameState/GameState.h"
ARM

extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetSerializedProgressState();
extern "C" void* Zone3D_GetMainInstance();
extern "C" bool Network_IsClientSession(unsigned*);
extern "C" int Network_GetLocalMemberId(char*);
extern "C" void* GameState_ReadUnkF8(GameState*);
extern "C" bool LinkedQueue_IsEmpty(const int*);
extern "C" void InitializeTypeFourStateAndBuffers(unsigned char*,int);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned*,unsigned);
extern "C" unsigned Script_GetSynchronizedCategoryProgressRecord(unsigned,unsigned);
extern "C" int FieldEvent_IsQueuedOrSynchronizing(unsigned char*);
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" void FieldEvent_QueueZoneEventAndDayTimer(char*,int,unsigned);
struct Bits{unsigned char first:1;unsigned char rest:7;};
// Original: arm9/ov017 @ 0x021CD748; symbol: func_ov017_021cd748; size: 0x2A0.
// Validates sender/zone and updates paired state, optionally copying current indexed tint.
extern "C" void Field_ApplyPairedStateRequest(unsigned sender,unsigned char *packet,GameState *game,unsigned char *resources,unsigned *connection){
 unsigned int value;unsigned char *node;unsigned short zoneId;unsigned char *global=(unsigned char*)_ZN9GameState11GetInstanceEv();unsigned *queue=*(unsigned**)(resources+0x36fc);node=*(unsigned char**)(resources+0x3734);
 GameState_GetSerializedProgressState();unsigned char *zone=(unsigned char*)Zone3D_GetMainInstance();zoneId=*(unsigned short*)zone;
 if((Network_IsClientSession(connection)&&!sender)||packet[14]){
 if(*(signed char*)(packet+15)>=0 && *(signed char*)(packet+15)!=Network_GetLocalMemberId((char*)connection))return;
 if(global[0x5cac])return;
 value=0;if(zoneId==*(unsigned short*)(packet+4))value=1;if(zoneId==*(unsigned short*)(packet+10))value=1;
 if(!value&&(*(unsigned char**)(resources+0x370c))[3]){unsigned short id=*(unsigned short*)GameState_ReadUnkF8(game);if(id==*(unsigned short*)(packet+4))value=1;if(id==*(unsigned short*)(packet+10))value=1;}
 if(!value)return;
 value=*(unsigned short*)(packet+8);if(!value)value=*(unsigned short*)(packet+6);if(!value)return;
 if(LinkedQueue_IsEmpty((int*)queue)||packet[14]){
 int changed=0;if(!node[3]){
 if(node[2]){if(*(unsigned short*)(packet+8)==*(unsigned short*)(node+0x118))return;*(unsigned short*)(node+8)=value;if(packet[14])node[0x116]=sender;changed=1;}
 else {if(value==*(unsigned short*)(zone+0x27d6))return;InitializeTypeFourStateAndBuffers(node,1);*(unsigned short*)(node+8)=value;if(packet[14])node[0x116]=sender;LinkedQueue_AppendAndMarkActive(queue,(unsigned)node);changed=1;}}
 if(changed&&Network_IsClientSession(connection)){
 unsigned char *state=(unsigned char*)GameState_GetSerializedProgressState();unsigned char *tint=(unsigned char*)Script_GetSynchronizedCategoryProgressRecord((unsigned)state,state[0x332]);
 ((Bits*)(node+0x178))->first=0;((Bits*)(node+0x178))->rest=0;node[0x179]=0;node[0x17a]=0;node[0x17b]=0;*(float*)(node+0x17c)=-1.0f;
 ((Bits*)(node+0x178))->first=1;node[0x179]=tint[0];node[0x17a]=tint[1];node[0x17b]=tint[2];*(unsigned*)(node+0x17c)=*(unsigned*)(packet+16);
 }
 }else{if(!FieldEvent_IsQueuedOrSynchronizing(node))*(unsigned short*)(resources+0x44ac)=value;}
 }else{if(Network_IsParentOrOffline(connection)&&FieldEvent_IsQueuedOrSynchronizing(node)){
 unsigned short value=*(unsigned short*)(packet+6);unsigned short first=*(unsigned short*)(node+0x18),second=*(unsigned short*)(node+0x16);
 if(value==first||value==second)FieldEvent_QueueZoneEventAndDayTimer((char*)node,sender,*(unsigned short*)(node+0x50));
 }}
}
