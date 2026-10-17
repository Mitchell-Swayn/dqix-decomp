#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Text_CopyBoundedNullTerminatedString(const char *,char *,int);
// Original: arm9/main @ 0x02046558; symbol: func_02046558; size: 0x1C.
    void Object_CopyBoundedTextToOffset46C(unsigned char *p,const char *text){
        Text_CopyBoundedNullTerminatedString(text,(char *)p+1132,64);
    }
}
