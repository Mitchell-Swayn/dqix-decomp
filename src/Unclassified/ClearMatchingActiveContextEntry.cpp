#include <globaldefs.h>
extern "C" {
    void *Object_GetGlobalConnectionState();
    bool IsFirstWordNonzero(void *);
    unsigned char *FindByteKeyAmongEightRecordsWhenContextActive(void *,int);
    void ClearFourBytes_Main020E303C(void *);
    bool TestActiveWordAndGlobalStateNonzero(void *);
    int ReadIndexedSignedField1038(void *);
    void func_ov017_021ceae4(int,unsigned char,unsigned char);
// Original: arm9/main @ 0x020E33B4; symbol: func_020e33b4; size: 0x74.
    void ClearMatchingActiveContextEntry(void *p,int id,int value){
        void *state=Object_GetGlobalConnectionState();
        if(!IsFirstWordNonzero(state))return;
        unsigned char *q=FindByteKeyAmongEightRecordsWhenContextActive(p,id);
        if(!q)return;
        if(q[0]!=value)return;
        ClearFourBytes_Main020E303C(q);
        if(!TestActiveWordAndGlobalStateNonzero(state))return;
        int mode=ReadIndexedSignedField1038(state);
        func_ov017_021ceae4(0,id,mode);
    }
}
