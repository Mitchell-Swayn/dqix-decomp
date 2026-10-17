#include <globaldefs.h>
extern "C" {
    void *Object_GetGlobalConnectionState();
    bool IsFirstWordNonzero(void *);
    int ReadIndexedSignedField1038(void *);
    void UpdateActiveContextEntryByIdAndValue(void *,int,unsigned char);
// Original: arm9/main @ 0x020E3328; symbol: func_020e3328; size: 0x40.
    void DispatchValueWithActiveContextMode(void *p,int id){
        void *state=Object_GetGlobalConnectionState();
        if(!IsFirstWordNonzero(state))return;
        UpdateActiveContextEntryByIdAndValue(p,id,ReadIndexedSignedField1038(state));
    }
}
