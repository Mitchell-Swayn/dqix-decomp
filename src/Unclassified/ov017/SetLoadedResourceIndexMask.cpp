#include <globaldefs.h>
extern "C" unsigned char* data_ov017_021d82e0[];
extern "C" void SetByteField55EToIndexMask(char*,int);
// Original: arm9/ov017 @ 0x0218B5F8; symbol: func_ov017_0218b5f8; size: 0x30.
// Field roles are unresolved; observed offsets are retained.
extern "C" ARM void SetLoadedResourceIndexMask(int index)
{
    unsigned char* p = data_ov017_021d82e0[1];
    if (p)
    {
        p = *(unsigned char**)(p + 0x36d0);
        if (p) SetByteField55EToIndexMask((char*)p,index);
    }
}
