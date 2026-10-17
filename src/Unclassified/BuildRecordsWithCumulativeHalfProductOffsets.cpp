#include <globaldefs.h>
extern "C" {
    struct R{
        int value;
        short a,b,c,d;
    };
    void ClearRecordFields00Through0A(void *);
// Original: arm9/main @ 0x02023064; symbol: func_02023064; size: 0x98.
    void BuildRecordsWithCumulativeHalfProductOffsets(R *out,unsigned int n,short *a,short *b,short *c,short *d){
        int offset=0;
        for(unsigned int i=0;i<n;i++){
            R *q=out+i;
            ClearRecordFields00Through0A(q);
            q->value=offset;
            q->a=a[i];
            q->b=b[i];
            q->c=c[i];
            q->d=d[i];
            offset+=(c[i]*d[i])/2;
        }
    }
}
