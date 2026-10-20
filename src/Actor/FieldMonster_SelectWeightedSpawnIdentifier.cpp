#include <globaldefs.h>
ARM
extern "C" int Random_ScaleIntegerByRandFraction(int);
struct Entry {unsigned short id:12;unsigned short weight:3;unsigned short flag:1;unsigned short value;};
struct Table {unsigned short a,count;unsigned unknown;Entry entries[1];};
// Original: arm9/main @ 0x02073FDC; symbol: func_02073fdc; size: 0x84.
extern "C" unsigned FieldMonster_SelectWeightedSpawnIdentifier(Table* p) {
    int total=0;
    for(int i=0;i<p->count;i++)total+=p->entries[i].weight;
    int random=Random_ScaleIntegerByRandFraction(total);
    int result=-1;int sum=0;int i=0;
    for(;i<p->count;i++) {
        Entry* entry=&p->entries[i];sum+=entry->weight;
        if(random<sum){result=entry->id;break;}
    }
    return result;
}
