#include <globaldefs.h>
extern "C" int ReadOneOf204PackedTwoBitValues(void*,int);
// Original: arm9/main @ 0x02095AE0; symbol: func_02095ae0; size: 0x50.
extern "C" int Object_TestStatusEmptyOrComplete(void* owner,int key)
{
    int result=1;
    bool empty=ReadOneOf204PackedTwoBitValues(owner,key)==0;
    if(!empty){
        bool complete=ReadOneOf204PackedTwoBitValues(owner,key)==1;
        if(!complete)result=0;
    }
    return result;
}
