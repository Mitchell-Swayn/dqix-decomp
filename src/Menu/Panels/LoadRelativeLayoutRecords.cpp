#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" char LoadRelativeLayoutRecords_TextNDS[];
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
struct Group {short key; unsigned short count;short* entries;short x,y,a,b,c,d,e;unsigned char flags,unknown;};
struct Cell {short key;unsigned char type;unsigned char font:4,color:4;short x,y,w,h;void* data;unsigned char flag;char pad[3];};
struct Layout {char pad[8];Group* groups;Cell* cells;char pad10[4];unsigned short groupCount,cellCount;};
struct InputGroup {unsigned unknown,offset;short x,y;unsigned short unknownc,count,key,a,b,c,d;char pad[2];};
struct InputCell {unsigned type;short x,y,key;unsigned short unknowna;unsigned short w,h;unsigned short w2,h2;char pad[20];};
struct Input {unsigned size,groupOffset;char magic[4];InputCell* cells;unsigned word10;char* entries;unsigned count;};
// Original: arm9/ov023 @ 0x021E20F0; symbol: func_ov023_021e20f0; size: 0x2E0.
// Relocates layout data and copies group/key and cell geometry into allocated runtime records.
extern "C" int LoadRelativeLayoutRecords(Layout* self,unsigned allocator,Input* input,void* required){
 if(!allocator)return 1;if(!input)return 1;if(!required)return 1;
 if(RuntimeMemory_CompareByteRanges(input->magic,LoadRelativeLayoutRecords_TextNDS,3))return 1;
 input->cells=(InputCell*)((char*)input+(unsigned)input->cells);
 input->entries=(char*)input+(unsigned)input->entries;
 self->groupCount=0;self->cellCount=0;self->groupCount=input->count;
 self->groups=(Group*)_ZN13SafeAllocator8AllocateEj(allocator,self->groupCount*24);
 InputGroup* source=(InputGroup*)((char*)input+input->groupOffset);
 unsigned short count=self->groupCount;
 for(unsigned short i=0;i<count;i++){
 InputGroup* src=source+i;Group* group=self->groups+i;
 group->key=-1;group->count=0;group->entries=0;group->x=group->y=0;
 group->a=-1;group->b=-1;group->c=-1;group->d=-1;group->e=0;group->flags=3;group->unknown=255;
 group->x=src->x;group->y=src->y;group->count=src->count;
 group->entries=(short*)_ZN13SafeAllocator8AllocateEj(allocator,src->count*2);
 char* entries=input->entries+src->offset;
 if(entries)memcpy(group->entries,entries,src->count*2);
 group->key=src->key;group->a=src->a;group->b=src->b;group->c=src->c;group->d=src->d;
 self->cellCount+=group->count;
 }
 self->cells=(Cell*)_ZN13SafeAllocator8AllocateEj(allocator,self->cellCount*20);
 input=(Input*)input->cells;
 for(allocator=0;allocator<self->cellCount;allocator=(unsigned short)(allocator+1)){
 InputCell* src=(InputCell*)input+allocator;Cell* cell=self->cells+allocator;
 cell->key=-1;cell->type=0;cell->font=10;cell->color=15;
 cell->x=cell->y=0;cell->w=cell->h=0;cell->data=0;cell->flag=0;
 cell->x=src->x;cell->y=src->y;cell->key=src->key;
 switch(src->type){
 case 0:cell->type=2;cell->w=src->w;cell->h=src->h;break;
 case 1:cell->type=1;cell->w=src->w;cell->h=src->h;break;
 case 2:break;
 case 3:if(!*(unsigned*)&src->w){cell->w=src->w2;cell->h=src->h2;}break;
 }
 }
 return 0;
}
