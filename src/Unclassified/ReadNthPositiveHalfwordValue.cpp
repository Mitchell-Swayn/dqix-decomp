#include <globaldefs.h>
extern "C" {
short *ReadValueForIndexThroughSeven(void *,int);unsigned int Object_ReadBoundedSlotGroupHalfwordCount(void *,int);
// Original: arm9/main @ 0x0207C6B8; symbol: func_0207c6b8; size: 0x74.
int ReadNthPositiveHalfwordValue(void *p,int i,int wanted){short *q=ReadValueForIndexThroughSeven(p,i);if(!q)return -1;short count=0;unsigned int n=Object_ReadBoundedSlotGroupHalfwordCount(p,i);for(unsigned int j=0;j<n;q++,j++){int v=*q;if(v>0){if(wanted==count)return v;count++;}}return -1;}
}
