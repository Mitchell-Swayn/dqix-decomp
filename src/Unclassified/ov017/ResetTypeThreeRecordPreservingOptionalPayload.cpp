#include <globaldefs.h>
extern "C" void InitializeFourWordsWithInvalidIndex(signed char*);
extern "C" void VectorizedMemset(void*,int,unsigned int);
// Original: arm9/ov017 @ 0x0219E310; symbol: func_ov017_0219e310; size: 0x74.
// Field roles are unresolved; observed offsets are retained.
extern "C" ARM void ResetTypeThreeRecordPreservingOptionalPayload(unsigned char* p, int clear)
{
    InitializeFourWordsWithInvalidIndex((signed char*)p);
    p[0]=3;
    p[8]=0;
    p[9]=0;
    p[10]=1;
    p[11]=0;
    p[12]=0;
    *(unsigned short*)(p+14)=0;
    *(unsigned short*)(p+16)=0;
    p[32]=0;
    *(unsigned short*)(p+34)=0;
    *(unsigned short*)(p+36)=0;
    *(unsigned int*)(p+40)=0;
    if (*(short*)(p+18) && !clear) return;
    VectorizedMemset(p+18,0,14);
}
