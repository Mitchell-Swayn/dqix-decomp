#include <globaldefs.h>
ARM
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned BattleScene_GetActiveInstance();char* BattleScene_ResolveCurrentActionRecord(char*);void* Combat_GetIndexedActionTarget(void*,int);int Combat_GetLatestTargetFromHistory(char*);int Util_TestSplitWordBit(unsigned long long*,unsigned);void* _ZN9GameState19GetCombatantByIndexEi(void*,int);void Combat_ClearPendingAndActiveMessages(char*);void QueueQualifiedLinkedPresentation(char*,int,int,int);void QueueLinkedRecordPresentationOnce(char*,int);int Combat_AppendActionMessage(char*,unsigned short,short,int,void*,short,unsigned short);}
#define Slot(v) (((v)>=0&&(v)<=3)?1:0)
struct Bits{unsigned char b0:1,b1:1,b2:1,b3:1,rest:4;};
// Original: arm9/ov025 @ 0x021EA604; symbol: func_ov025_021ea604; size: 0x354.
// Queues secondary-record presentation keys, tracking class uniqueness and conditional shared entries.
extern "C" void QueueSecondaryRecordPresentation(unsigned char* self,int ordinal,int unused,char* item){
 void* game=_ZN9GameState11GetInstanceEv();char* record=BattleScene_ResolveCurrentActionRecord((char*)BattleScene_GetActiveInstance());char* linked=(char*)Combat_GetIndexedActionTarget(record,ordinal);int queued=0;
 if(self[0x5d0]){
 int unique=1;bool slot=Slot(*(short*)(linked+14))?true:false;
 for(int i=ordinal+1;i<(unsigned char)record[9];i++){
 char* next=(char*)Combat_GetIndexedActionTarget(record,i);bool nextSlot=Slot(*(short*)(next+14))?true:false;
 if((slot&&nextSlot)||(!slot&&!nextSlot)){unique=0;break;}}
 for(char* node=*(char**)(item+8);node;node=*(char**)(node+4))if(*(unsigned short*)node==8){int index=Combat_GetLatestTargetFromHistory(linked);((short*)(self+0x5d2))[*(int*)(self+0x5e4)]=index;(*(int*)(self+0x5e4))++;*(short*)node=0;}
 if(unique){queued=1;self[0x5d1]=queued;}
 }
 if(linked){int index=Combat_GetLatestTargetFromHistory(linked);if(!item)return;
 if(Util_TestSplitWordBit((unsigned long long*)item,11)){char* object=(char*)_ZN9GameState19GetCombatantByIndexEi(game,*(short*)(linked+14));if(object)index=*(short*)(*(char**)(object+0x138)+40);}
 if(*(unsigned short*)record==0x399)index=*(short*)(linked+12);
 int first=0;if(!self[0x738]&&*(unsigned short*)(self+0x748)<500&&!self[0x5cc])first=1;
 int allow=1;
 if(Slot(index)&&((Bits*)(record+12))->b0&&!Util_TestSplitWordBit((unsigned long long*)item,1))allow=0;
 else if(!Slot(index)&&((Bits*)(record+12))->b3&&!Util_TestSplitWordBit((unsigned long long*)item,1))allow=0;
 if(allow&&first)Combat_ClearPendingAndActiveMessages((char*)self+0x5e8);
 if(allow||queued){int enqueue=0;if(queued)enqueue=1;int target=(short)index;if(queued)target=-2;QueueQualifiedLinkedPresentation((char*)self,Slot(index)?1:0,enqueue,target);}
 for(char* node=*(char**)(item+8);node;node=*(char**)(node+4))Combat_AppendActionMessage((char*)self+0x5e8,*(unsigned short*)node,(short)index,1,item,-1,0);
 if(self[0x5cc]&&Util_TestSplitWordBit((unsigned long long*)item,2))QueueLinkedRecordPresentationOnce((char*)self,Slot(index)?1:0);
 }
 self[0x5c5]++;
}
