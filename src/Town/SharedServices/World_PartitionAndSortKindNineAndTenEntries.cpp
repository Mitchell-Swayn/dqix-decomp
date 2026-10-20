#include <globaldefs.h>
ARM
struct Record {unsigned char pad[11];unsigned char priority:7,flag:1;unsigned unknown:4,kind:4,pad8:7,rank:4,order:5,rest:8;};
struct Zone;
struct Owner {unsigned char pad[0xf4];Record* entries[31];Zone* zone;};
extern "C" int _ZN13ZoneState084019CountEntriesOfKind9Ev(Zone*);
extern "C" int _ZN13ZoneState084020CountEntriesOfKind10Ev(Zone*);
// Original: arm9/ov003 @ 0x02170688; symbol: func_ov003_02170688; size: 0x210.
extern "C" void World_PartitionAndSortKindNineAndTenEntries(Owner* self) {
 Zone* zone=self->zone;
 int total=*(int*)((unsigned char*)zone+0x1b38);
 int nine=_ZN13ZoneState084019CountEntriesOfKind9Ev(zone);
 int special=nine+_ZN13ZoneState084020CountEntriesOfKind10Ev(zone);
 int out=0;
 for(int i=0;i<total;++i) {
  Record* entry=self->entries[i];
  if(entry->kind==9 || entry->kind==10) {
   self->entries[i]=self->entries[out];
   self->entries[out]=entry;
   ++out;
  }
 }
 for(int i=0;i<special-1;++i) {
  for(int j=0;j<special-1-i;++j) {
   Record* a=self->entries[j];
   Record* b=self->entries[j+1];
   if(a->priority<b->priority) {self->entries[j]=b;self->entries[j+1]=a;}
   else if(a->priority<=b->priority) {
    if(a->rank<b->rank) {self->entries[j]=b;self->entries[j+1]=a;}
    else if(a->rank<=b->rank) {
     if(a->order<b->order) {self->entries[j]=b;self->entries[j+1]=a;}
    }
   }
  }
 }
 int n=0;
 for(int i=special;i<total-1;++i,++n) {
  for(int j=special;j<total-1-n;++j) {
   Record* a=self->entries[j];
   Record* b=self->entries[j+1];
   if(a->priority<b->priority) {self->entries[j]=b;self->entries[j+1]=a;}
   else if(a->priority<=b->priority) {
    if(a->rank<b->rank) {self->entries[j]=b;self->entries[j+1]=a;}
    else if(a->rank<=b->rank) {
     if(a->order<b->order) {self->entries[j]=b;self->entries[j+1]=a;}
     else if(a->order<=b->order) {
      if(a->kind>b->kind) {self->entries[j]=b;self->entries[j+1]=a;}
     }
    }
   }
  }
 }
}
