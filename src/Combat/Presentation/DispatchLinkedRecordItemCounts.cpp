#include <globaldefs.h>
ARM
extern "C" {void* __clear(void*,unsigned);void* Combat_GetCommandActorSnapshot(void*,int);void* Combat_GetIndexedActionTarget(void*,int);int BattleScene_PresentActionResult(void*,void*,int,int,int,int,int);}
// Original: arm9/ov025 @ 0x021D8AB8; symbol: func_ov025_021d8ab8; size: 0x144.
// Dispatches each indexed item count from the primary or secondary record for one or all six categories.
extern "C" void DispatchLinkedRecordItemCounts(void* self,void* record,int mode,int category,int index) {
 int storage[6];__clear(storage,24);int* counts=storage;
 if(mode==0){unsigned char* node=(unsigned char*)Combat_GetCommandActorSnapshot(record,index);if(node){counts[0]=node[38];counts[1]=node[40];counts[2]=node[41];counts[3]=node[43];counts[4]=node[42];counts[5]=node[39];}}
 else if((unsigned)(mode-1)<=2){unsigned char* node=(unsigned char*)Combat_GetIndexedActionTarget(record,index);if(node){counts[0]=node[24];counts[1]=node[25];counts[2]=node[26];}}
 if(category==6){for(int kind=0;kind<6;kind++)for(int item=0;item<counts[kind];item++)BattleScene_PresentActionResult(self,record,mode,kind,index,item,0);}
 else for(int item=0;item<counts[category];item++)BattleScene_PresentActionResult(self,record,mode,category,index,item,0);
}
