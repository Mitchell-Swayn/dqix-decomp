#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
signed char *ReadOneOfEightWordFieldsAtOffsetBF0(void *,int);int Object_ReadBoundedSlotGroupHalfwordCount(void *,int);
// Original: arm9/main @ 0x0207C638; symbol: func_0207c638; size: 0x5C.
short CountPositiveSignedByteQuantities(void *p,int i){signed char *q=ReadOneOfEightWordFieldsAtOffsetBF0(p,i);int n=Object_ReadBoundedSlotGroupHalfwordCount(p,i);short count=0;for(short j=0;j<n;j++)if(q[j]>0)count++;return count;}
}
