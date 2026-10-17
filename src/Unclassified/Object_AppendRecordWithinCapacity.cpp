#include <globaldefs.h>
ARM
#pragma optimize_for_size off
struct Entry {
    unsigned value; short a,b,c,d,e,f;unsigned short g;unsigned char h,i,j,pad[3];
    unsigned k,l,m,n;short o;unsigned char q,r,s,t,pad2[2];
};
struct Table {Entry* entries;short count,capacity;};
// Original: arm9/main @ 0x0207F5D0; symbol: func_0207f5d0; size: 0xDC.
extern "C" void Object_AppendRecordWithinCapacity(Table* table,const Entry* src){
    if(!table->entries)return;
    if(table->capacity<=table->count)return;
    Entry* dst=&table->entries[table->count];
    dst->value=src->value;
    dst->a=src->a;dst->b=src->b;dst->c=src->c;dst->d=src->d;dst->e=src->e;dst->f=src->f;
    dst->g=src->g;dst->h=src->h;dst->i=src->i;dst->j=src->j;
    dst->k=src->k;dst->l=src->l;dst->m=src->m;dst->n=src->n;
    dst->o=src->o;dst->q=src->q;dst->r=src->r;dst->s=src->s;dst->t=src->t;
    ++table->count;
}
