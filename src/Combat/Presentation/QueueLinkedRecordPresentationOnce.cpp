#include <globaldefs.h>
ARM
extern "C" {void* __clear(void*,unsigned);unsigned BattleScene_GetActiveInstance();char* BattleScene_ResolveCurrentActionRecord(char*);void* Combat_GetIndexedActionTarget(void*,int);int Combat_GetLatestTargetFromHistory(char*);int Util_TestSplitWordBit(unsigned long long*,unsigned);int Combat_AppendActionMessage(char*,unsigned short,short,int,void*,short,unsigned short);}
#define InRange(x,a,b) (((x)>=(a)&&(x)<=(b))?1:0)
// Original: arm9/ov025 @ 0x021EAD5C; symbol: func_ov025_021ead5c; size: 0x1EC.
// Queues mode-specific presentation entries once, scanning eligible secondary linked records.
extern "C" void QueueLinkedRecordPresentationOnce(char* self,int mode) {
 if(!mode){if(((unsigned char*)self)[0x5ca])return;self[0x5ca]=1;}
 if(mode){if(((unsigned char*)self)[0x5cb])return;self[0x5cb]=1;}
 char* record=BattleScene_ResolveCurrentActionRecord((char*)BattleScene_GetActiveInstance());
 int indices[4];unsigned char seen[4];__clear(seen,4);int special=0;__clear(indices,16);
 int count=0;
 if(*(unsigned short*)(record+30)||*(unsigned short*)(record+32)) {
 char* linked=(char*)Combat_GetIndexedActionTarget(record,0);
 while(linked){char* child=*(char**)linked;
 while(child){
 if(!Util_TestSplitWordBit((unsigned long long*)child,13)&&*(short*)(child+14)<=0){
 int index=Combat_GetLatestTargetFromHistory(linked);
 if(InRange(index,192,199)){if(!special)special=index;break;}
 if(InRange(index,0,3)){if(!seen[index]){indices[count]=index;seen[index]=1;count++;}}break;
 }
 child=*(char**)(child+32);
 }
 linked=*(char**)(linked+32);
 }
 }
 if(mode){for(int i=0;i<*(int*)(self+0x5e4);i++)Combat_AppendActionMessage(self+0x5e8,8,*(short*)(self+0x5d2+i*2),0,0,-1,0);*(int*)(self+0x5e4)=0;}
 else if(special)Combat_AppendActionMessage(self+0x5e8,*(unsigned short*)(record+32),(short)special,0,0,-1,0);
}
