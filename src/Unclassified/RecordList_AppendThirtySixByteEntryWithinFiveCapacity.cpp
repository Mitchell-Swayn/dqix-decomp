#pragma optimization_level 4
#include <globaldefs.h>
extern "C" {
    struct B{
        unsigned char bytes[16];
    };
    struct R{
        B bytes;
        unsigned char a,b,c,d;
        int e,f,g;
        unsigned short h,i;
    };
// Original: arm9/main @ 0x020D3CF0; symbol: func_020d3cf0; size: 0x88.
    void RecordList_AppendThirtySixByteEntryWithinFiveCapacity(unsigned char *p,const R *q){
        int count=*(int *)(p+180);
        if(count>=5)return;
        R *entry=(R *)(p+count*36);
        *(int *)(p+180)=count+1;
        entry->bytes=q->bytes;
        entry->a=q->a;
        entry->b=q->b;
        entry->c=q->c;
        entry->d=q->d;
        entry->e=q->e;
        entry->f=q->f;
        entry->g=q->g;
        entry->h=q->h;
        entry->i=q->i;
    }
}
