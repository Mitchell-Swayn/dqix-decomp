#include <globaldefs.h>
extern "C" {
    void *Object_GetGlobalConnectionState();
    int IsFirstWordNonzero(void *);
    unsigned char *FindByteKeyAmongEightRecordsWhenContextActive(void *,int);
    int ReadIndexedSignedField1038(void *);
    void ClearFourBytes_Main020E303C(void *);
// Original: arm9/main @ 0x020E3468; symbol: func_020e3468; size: 0x54.
    void RecordArray_ClearMatchingCurrentOwnerEntry(void *p,int id){
        void *state=Object_GetGlobalConnectionState();
        if(!IsFirstWordNonzero(state))return;
        unsigned char *q=FindByteKeyAmongEightRecordsWhenContextActive(p,id);
        if(!q)return;
        if(q[0]!=ReadIndexedSignedField1038(state))return;
        ClearFourBytes_Main020E303C(q);
    }
}
