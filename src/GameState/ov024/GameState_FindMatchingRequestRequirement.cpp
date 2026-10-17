#include <globaldefs.h>
ARM
struct Requirement { unsigned short id,area,condition,rank,exact; unsigned short index; unsigned char category,pad; };
struct Request { unsigned id:9; unsigned a:5; unsigned flag14:1; unsigned flag15:1; unsigned rest:16; unsigned data[3]; };
struct Queue { unsigned char count,pad[3]; Request entries[1]; };
struct Field22 { unsigned short a:2; unsigned short kind:4; unsigned short b:10; };
extern "C" {
Queue* Object_GetGlobalRequestQueue();
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetIndexList(void*);
short SumIndexedValuesAcrossPresentPartyIds(void*,int);
bool Object_TestElement5Mask10(unsigned*);
extern Requirement data_ov024_021fe9b8[];
}
// Original: arm9/ov024 @ 0x021DF71C; symbol: func_ov024_021df71c; size: 0x208.
extern "C" int GameState_FindMatchingRequestRequirement(char* self,unsigned score,int category,unsigned short* outIndex,unsigned short* outArea,unsigned short* outId) {
 Queue* queue=Object_GetGlobalRequestQueue();
 if(!queue->count)return 0;
 void* indices=GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
 int area=0;
 if(*(char**)(self+0x144))area=*(short*)(*(char**)(self+0x144)+8);
 for(int i=0;i<queue->count;i++) {
  if(queue->entries[i].flag15)continue;
  if(queue->entries[i].flag14)continue;
  for(int j=0;j<7;j++) {
   Requirement* r=data_ov024_021fe9b8+j;
   if(r->id!=queue->entries[i].id || area!=r->area)continue;
   if(category && !r->category)continue;
   if(!category && r->category)continue;
   if(SumIndexedValuesAcrossPresentPartyIds(indices,(short)r->index)>0)continue;
   if(r->condition) {
    if(r->condition==1) {
     if(!Object_TestElement5Mask10(*(unsigned**)(self+0x138)))continue;
    } else if(r->condition==2) {
     if(**(unsigned short**)(self+0x138)>700)continue;
    } else if(r->condition==3) {
     if(((Field22*)(*(char**)(self+0x138)+0x22))->kind!=3)continue;
    }
   }
   if(r->rank) {
    unsigned rank=r->rank;
    if(rank>=40000) {
     rank=40000;
     if(score<(unsigned)rank)continue;
    } else if((int)rank/100!=(int)score/100)continue;
   }
   if(r->exact && r->exact!=score)continue;
   *outIndex=r->index;
   *outArea=r->area;
   *outId=r->id;
   return 1;
  }
 }
 return 0;
}
