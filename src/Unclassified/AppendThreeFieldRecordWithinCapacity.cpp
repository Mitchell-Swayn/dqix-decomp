#include <globaldefs.h>
extern "C" {
    struct R{
        int a,b,c;
    };
    struct L{
        R *entries;
        unsigned short capacity,count;
    };
// Original: arm9/main @ 0x020A1568; symbol: func_020a1568; size: 0x54.
    void AppendThreeFieldRecordWithinCapacity(L *p,const R *value){
        if(!value)return;
        if(p->capacity<=p->count)return;
        R *q=p->entries+p->count;
        q->a=value->a;
        q->b=value->b;
        q->c=value->c;
        p->count++;
    }
}
