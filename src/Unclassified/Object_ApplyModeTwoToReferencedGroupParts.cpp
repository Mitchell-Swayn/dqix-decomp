#include <globaldefs.h>
extern "C" {
    short *FindNonnegativeKeyInCountedRecordArray(void *);
    void SetResolvedEntryByte2ABits(void *,int,int);
// Original: arm9/main @ 0x02080608; symbol: func_02080608; size: 0x54.
    void Object_ApplyModeTwoToReferencedGroupParts(unsigned char *p){
        short *q=FindNonnegativeKeyInCountedRecordArray(p+12);
if(!q)return;
        for(unsigned char i=0;i<((unsigned char *)q)[19];i++)SetResolvedEntryByte2ABits(p+4,(*(short **)q)[i],2);
    }
}
