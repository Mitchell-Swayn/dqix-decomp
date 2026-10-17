#include <globaldefs.h>
extern "C" {
    bool TestActiveWordAndGlobalStateNonzero(void *);
    int Object_FindSignedByteKeyInSixteenEntries(void *,int);
// Original: arm9/main @ 0x0202C718; symbol: func_0202c718; size: 0x40.
    void ClearResolvedSlotBitAt1010(unsigned char *p,int id){
        if(TestActiveWordAndGlobalStateNonzero(p))return;
        int i=Object_FindSignedByteKeyInSixteenEntries(p,id);
        p[0x1010]&=~(1<<i);
    }
}
