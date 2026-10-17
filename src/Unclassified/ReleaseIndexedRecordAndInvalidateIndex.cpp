#include <globaldefs.h>
extern "C" {
    extern unsigned char *data_02105244;
    void ReleaseIndexedReferenceAndResetAtZero(unsigned char *,short *);
// Original: arm9/main @ 0x0203C198; symbol: func_0203c198; size: 0x30.
    void ReleaseIndexedRecordAndInvalidateIndex(unsigned char *p){
        if(!data_02105244)return;
        ReleaseIndexedReferenceAndResetAtZero(data_02105244,(short *)(p+20));
        *(short *)(p+20)=-1;
    }
}
