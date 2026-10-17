#include <globaldefs.h>
extern "C" {
    unsigned char *FindNonnegativeKeyInCountedRecordArray(char *,int);
    void SetResolvedEntryByte2ABits(char *,int,int);
// Original: arm9/main @ 0x02080B54; symbol: func_02080b54; size: 0x58.
    void SetFlagOneForEachListedId(char *p,int id){
        unsigned char *q=FindNonnegativeKeyInCountedRecordArray(p+12,id);
        if(!q)return;
        for(short i=0;i<q[19];i++)SetResolvedEntryByte2ABits(p+4,(*(short **)q)[i],1);
    }
}
