#include <globaldefs.h>
extern "C" int Script_GetPackedEntryState(void*,int);
// Original: arm9/main @ 0x02095AE0; symbol: func_02095ae0; size: 0x50.
extern "C" int Quest_IsOrderStatusZeroOrOne(void* owner,int key)
{
    int result=1;
    bool empty=Script_GetPackedEntryState(owner,key)==0;
    if(!empty){
        bool complete=Script_GetPackedEntryState(owner,key)==1;
        if(!complete)result=0;
    }
    return result;
}
