#include <globaldefs.h>
ARM
struct GameState;struct GameObject;
extern "C" {void* _ZN9GameState11GetInstanceEv();GameObject* GameState_FindIndexedObjectWithFlag1000(GameState*,int);void* GameState_GetIndexList(GameState*);void* Object_GetGlobalConnectionState();void* ReadGlobalAt02100044();void MoveQueuedRecordAndApplySourceValue(void*,const void*,short);}
struct Message {unsigned char tag;int values[4];};
// Original: arm9/ov017 @ 0x021C8654; symbol: func_ov017_021c8654; size: 0xA0.
extern "C" void QueueMissingIndexedObjectValuesMessage77(){
GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();Object_GetGlobalConnectionState();void* queue=ReadGlobalAt02100044();Message message;message.tag=0x77;
int* values=message.values;
for(int i=0;i<4;i++)values[i]=-1;
unsigned char* list=(unsigned char*)GameState_GetIndexList(game);
for(int i=0;i<list[0xf7c];i++){
int index=(list+i)[0xf78];
if(!GameState_FindIndexedObjectWithFlag1000(game,index))values[index]=*(int*)(list+0xf6c);
}
MoveQueuedRecordAndApplySourceValue(queue,&message,0);
}
