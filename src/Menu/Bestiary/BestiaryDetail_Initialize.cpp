#include "Filesystem/BackgroundLoader.h"
struct GameState{static GameState* GetInstance();};struct LightingManager{static LightingManager* GetInstance();};
extern "C" {
struct Bits{unsigned char a:1,b:1,c:1,d:1,top:4;};
struct Owner {unsigned words[3];unsigned char archive[0x10];unsigned char table[0x20];unsigned char* allocators;void* object;unsigned word;void* current;void* previous;unsigned* descriptor;unsigned* previousDescriptor;void* fields[5];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags;Bits bits;unsigned char gap[3];short tasks[5];unsigned char gap2[8];void* pointer;unsigned char list[0x10];};
// Original data: arm9/ov014 @ 0x2189800; symbol: data_ov014_02189800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern unsigned BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[];void BestiaryInfo_InitializeSelection(void*);void BestiaryInfo_ResetSelection(void*);void BestiaryHabitat_InitializeLoader(void*);void BestiaryHabitat_CancelLoad(void*);void BestiaryDetail_ResetMonsterStatSummary(void*);void* memset(void*,int,unsigned);void GameState_SetUnknown3b0(GameState*,unsigned);int func_020328b4(void*);void func_02032730(void*);
// Original: arm9/ov014 @ 0x021844C4; symbol: func_ov014_021844c4; size: 0x110.
void BestiaryDetail_Initialize(Owner* p){BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[3]=0;p->words[0]=0;p->words[1]=0;p->words[2]=0;BestiaryInfo_InitializeSelection(p->archive);BestiaryHabitat_InitializeLoader(p->table);p->allocators=0;p->object=0;p->word=0;p->current=0;p->previous=0;p->descriptor=0;p->previousDescriptor=0;p->fields[0]=0;p->fields[1]=0;p->fields[2]=0;p->fields[3]=0;p->fields[4]=0;p->task=-1;p->load=-1;p->otherTask=-1;p->frame=0;p->f7c=0;p->f7d=0;p->count=0;p->active=0;p->selected=0;p->flags=0;p->bits.a=0;p->bits.b=0;p->bits.c=0;p->bits.top=0;p->bits.d=0;for(int i=0;i<5;i++)p->tasks[i]=-1;p->pointer=0;BestiaryDetail_ResetMonsterStatSummary(p->list);memset((unsigned char*)p+0x90,0,3);((unsigned char*)p)[0x93]=0;((unsigned char*)p)[0x94]=0;}
}
