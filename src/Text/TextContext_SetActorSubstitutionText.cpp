#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Text_CopyBoundedNullTerminatedString(const char *,char *,int);
// Original: arm9/main @ 0x02046504; symbol: func_02046504; size: 0x1C.
    void TextContext_SetActorSubstitutionText(unsigned char *p,const char *text){
        Text_CopyBoundedNullTerminatedString(text,(char *)p+940,64);
    }
}
