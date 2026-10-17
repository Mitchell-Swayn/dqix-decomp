#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Text_CopyBoundedNullTerminatedString(const char *,char *,int);
// Original: arm9/main @ 0x020464E8; symbol: func_020464e8; size: 0x1C.
    void CopyBoundedTextIntoIndexedSixtyFourByteSlot(unsigned char *p,int id,const char *text){
        Text_CopyBoundedNullTerminatedString(text,(char *)p+748+id*64,64);
    }
}
