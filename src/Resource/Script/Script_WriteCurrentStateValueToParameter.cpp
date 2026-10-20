#include <globaldefs.h>
extern "C" {
    void *ScriptQueryContext_GetActiveInstance();
    int TextContext_GetSharedChoiceResult(void *);
    void Script_WriteIntegerReferenceOutput(void *,int);
// Original: arm9/main @ 0x0209DAF8; symbol: func_0209daf8; size: 0x30.
    bool Script_WriteCurrentStateValueToParameter(void *p){
        void *q=ScriptQueryContext_GetActiveInstance();
        if(!q)return false;
        Script_WriteIntegerReferenceOutput(p,TextContext_GetSharedChoiceResult(q));
        return true;
    }
}
