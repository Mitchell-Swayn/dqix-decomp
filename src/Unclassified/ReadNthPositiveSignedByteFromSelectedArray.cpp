#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
signed char *ReadOneOfEightWordFieldsAtOffsetBF0(void *,int);unsigned int Object_ReadBoundedSlotGroupHalfwordCount(void *,int);
// Original: arm9/main @ 0x0207C72C; symbol: func_0207c72c; size: 0x74.
int ReadNthPositiveSignedByteFromSelectedArray(void *p,int i,int wanted){signed char *q=ReadOneOfEightWordFieldsAtOffsetBF0(p,i);if(!q)return 0;short count=0;unsigned int n=Object_ReadBoundedSlotGroupHalfwordCount(p,i);for(unsigned int j=0;j<n;q++,j++){int v=*q;if(v>0){if(wanted==count)return v;count++;}}return 0;}
}
