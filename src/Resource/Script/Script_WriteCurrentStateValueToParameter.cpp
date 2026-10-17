#include <globaldefs.h>
extern "C" {
    void *ReadWordAtOffset0();
    int ReadGlobalContextSelectionIndex(void *);
    void SetNestedSecondWordForTypeThree(void *,int);
// Original: arm9/main @ 0x0209DAF8; symbol: func_0209daf8; size: 0x30.
    bool Script_WriteCurrentStateValueToParameter(void *p){
        void *q=ReadWordAtOffset0();
        if(!q)return false;
        SetNestedSecondWordForTypeThree(p,ReadGlobalContextSelectionIndex(q));
        return true;
    }
}
