#include <globaldefs.h>
ARM
struct Entry { short a,b; unsigned c,d; unsigned char e,f,g,h; short i; unsigned char j,k; };
struct List { Entry* entries; short capacity,count; };
// Original: arm9/ov003 @ 0x0215E790; symbol: func_ov003_0215e790; size: 0x94.
extern "C" void Util_AppendTwentyByteRecordIfSpace(List* list,const Entry* source) {
 if(!list->entries) return;
 if(list->capacity<=list->count) return;
 Entry* target=&list->entries[list->count];
 target->a=source->a;
 target->b=source->b;
 target->c=source->c;
 target->d=source->d;
 target->e=source->e;
 target->f=source->f;
 target->g=source->g;
 target->h=source->h;
 target->i=source->i;
 target->j=source->j;
 target->k=source->k;
 ++list->count;
}
