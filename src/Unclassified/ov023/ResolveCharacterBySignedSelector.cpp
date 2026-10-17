#include <globaldefs.h>
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetObjectWithFlag100(void*,int);
int GameState_ReadProtagonistObjectIndex(void*);
void __clear(void*,int);
int GameState_CopyByteBufferAtOffset5718(void*,void*);
}

// Original: arm9/ov023 @ 0x021E8F28; symbol: func_ov023_021e8f28; size: 0xC0.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM void* ResolveCharacterBySignedSelector(int selector)
{
    void* state=_ZN9GameState11GetInstanceEv();
    void* result=0;
    if(selector>=0)
    {
        int valid=(selector>=0 && selector<=3) ? 1 : 0;
        if(valid) result=GameState_GetObjectWithFlag100(state,selector);
    }
    else if(selector==-1) result=GameState_GetObjectWithFlag100(state,GameState_ReadProtagonistObjectIndex(state));
    else
    {
        unsigned char ids[4];
        __clear(ids,4);
        int n=GameState_CopyByteBufferAtOffset5718(state,ids);
        int i=-1-selector;
        if(i<n) result=GameState_GetObjectWithFlag100(state,ids[i]);
    }
    return result;
}
