#include <globaldefs.h>
extern "C" {
    void Object_InitializeThirtyTwoByteBufferAndSlotFlags(void *);
// Original: arm9/main @ 0x0203C54C; symbol: func_0203c54c; size: 0x5C.
    void ReleaseIndexedReferenceAndResetAtZero(unsigned char *p,short *index){
        short i=*index;
        if(i<0)return;
        unsigned char *q=p+4+i*40;
        *index=-1;
        if(!q[36])return;
        q[36]--;
        if(q[36])return;
        Object_InitializeThirtyTwoByteBufferAndSlotFlags(q);
        (*(unsigned short *)(p+0x512))--;
    }
}
