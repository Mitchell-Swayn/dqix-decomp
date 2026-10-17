#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" int EntryTable_SelectMinimumUnmarkedPackedKey(void *, int, unsigned int);
ARM
// Original: arm9/main @ 0x020A1698; symbol: func_020a1698; size: 0x84.
extern "C" void ClearPackedVisitedBitsAndRebuildDerivedSequence(char *p, unsigned int arg) {
    *(int *)(p+8)=0; int n=(unsigned short)*(unsigned short *)(p+4)-1;
    int bytes=n + (int)((unsigned int)(n >> 2) >> 0x1d); bytes=(bytes >> 3)+1;
    memset(*(void **)(p+0xc),0,bytes);
    int next; *(int *)(p+8)=EntryTable_SelectMinimumUnmarkedPackedKey(p,2,arg); next=*(int *)(p+8);
    if (next) { while (next) { int item=EntryTable_SelectMinimumUnmarkedPackedKey(p,2,arg); *(int *)(next+8)=item; next=item; } }
    p[0x10]=2;
}
