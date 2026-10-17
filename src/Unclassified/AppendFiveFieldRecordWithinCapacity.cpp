#include <globaldefs.h>
extern "C" {
    struct R{
        int a,b,c,d,e;
    };
    struct L{
        R *entries;
        int capacity,count;
    };
// Original: arm9/main @ 0x020E587C; symbol: func_020e587c; size: 0x60.
    void AppendFiveFieldRecordWithinCapacity(L *p,const R *value){
        if(!value)return;
        if(p->capacity<=p->count)return;
        R *q=p->entries+p->count;
        q->a=value->a;
        q->b=value->b;
        q->c=value->c;
        q->d=value->d;
        q->e=value->e;
        p->count++;
    }
}
