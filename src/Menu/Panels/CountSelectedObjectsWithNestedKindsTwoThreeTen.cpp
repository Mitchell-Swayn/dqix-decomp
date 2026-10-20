#include <globaldefs.h>
ARM
extern "C" {void __clear(void*,unsigned);void* _ZN9GameState11GetInstanceEv();void* GameState_GetObjectWithFlag100(void*,int);int GameState_CopyProtagonistPartySlotList(void*,void*);void Script_WriteIntegerReferenceOutput(void*,int);}
// Original: arm9/ov023 @ 0x021EA51C; symbol: func_ov023_021ea51c; size: 0x88.
extern "C" int CountSelectedObjectsWithNestedKindsTwoThreeTen(void* out){
void* game=_ZN9GameState11GetInstanceEv();unsigned char ids[4];__clear(ids,4);
int n=GameState_CopyProtagonistPartySlotList(game,ids);int count=0;
for(int i=0;i<n;i++){
char* obj=(char*)GameState_GetObjectWithFlag100(game,ids[i]);
if(obj){int kind=*(int*)(*(char**)(obj+0x150)+0x950);if(kind==2||kind==3||kind==10)count++;}
}
Script_WriteIntegerReferenceOutput(out,count);return 1;
}
