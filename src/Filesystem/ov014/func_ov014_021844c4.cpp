#include "Filesystem/BackgroundLoader.h"
struct GameState{static GameState* GetInstance();};struct LightingManager{static LightingManager* GetInstance();};
extern "C" {
struct Bits{unsigned char a:1,b:1,c:1,d:1,top:4;};
struct Owner {unsigned words[3];unsigned char archive[0x10];unsigned char table[0x20];unsigned char* allocators;void* object;unsigned word;void* current;void* previous;unsigned* descriptor;unsigned* previousDescriptor;void* fields[5];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags;Bits bits;unsigned char gap[3];short tasks[5];unsigned char gap2[8];void* pointer;unsigned char list[0x10];};
extern unsigned data_ov014_02189800[];void Object_Clear16Bytes(void*);void ClearSixteenBytes_Main02096FC4(void*);void func_ov014_02188bd0(void*);void func_ov014_02188d10(void*);void func_ov014_021845d4(void*);void* memset(void*,int,unsigned);void GameState_SetUnknown3b0(GameState*,unsigned);int func_020328b4(void*);void func_02032730(void*);
// Original: arm9/ov014 @ 0x021844C4; symbol: func_ov014_021844c4; size: 0x110.
void func_ov014_021844c4(Owner* p){data_ov014_02189800[3]=0;p->words[0]=0;p->words[1]=0;p->words[2]=0;Object_Clear16Bytes(p->archive);func_ov014_02188bd0(p->table);p->allocators=0;p->object=0;p->word=0;p->current=0;p->previous=0;p->descriptor=0;p->previousDescriptor=0;p->fields[0]=0;p->fields[1]=0;p->fields[2]=0;p->fields[3]=0;p->fields[4]=0;p->task=-1;p->load=-1;p->otherTask=-1;p->frame=0;p->f7c=0;p->f7d=0;p->count=0;p->active=0;p->selected=0;p->flags=0;p->bits.a=0;p->bits.b=0;p->bits.c=0;p->bits.top=0;p->bits.d=0;for(int i=0;i<5;i++)p->tasks[i]=-1;p->pointer=0;func_ov014_021845d4(p->list);memset((unsigned char*)p+0x90,0,3);((unsigned char*)p)[0x93]=0;((unsigned char*)p)[0x94]=0;}
}
