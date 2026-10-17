#include <globaldefs.h>
extern "C" int Memory_AllocateAndInitialize368ByteRecord(unsigned int *, unsigned int);
extern "C" void WriteThreeWordsAtOffsets28Through30(unsigned int,unsigned int,unsigned int,unsigned int);
extern "C" void ResourceTracks_InitializeCurrentValuesAndSlopes(unsigned int);
ARM
// Original: arm9/main @ 0x02055718; symbol: func_02055718; size: 0x5C.
extern "C" int Object_BindTwoResourcesAndUpdateResolvedState(unsigned int *p, unsigned int a, unsigned int b) {
    if (a == 0) return 0; if (b == 0) return 0;
    p[0]=b; p[2]=a; int result=Memory_AllocateAndInitialize368ByteRecord(p+1,*p);
    if (result) { WriteThreeWordsAtOffsets28Through30(p[1],p[3],p[2],p[0]); ResourceTracks_InitializeCurrentValuesAndSlopes(p[1]); }
    return 1;
}
