#include <globaldefs.h>
extern "C" {
short *Inventory_GetGroupItemIds(void *,int);unsigned int Inventory_GetGroupCapacity(void *,int);
// Original: arm9/main @ 0x0207C6B8; symbol: func_0207c6b8; size: 0x74.
int Inventory_GetNthPositiveItemId(void *p,int i,int wanted){short *q=Inventory_GetGroupItemIds(p,i);if(!q)return -1;short count=0;unsigned int n=Inventory_GetGroupCapacity(p,i);for(unsigned int j=0;j<n;q++,j++){int v=*q;if(v>0){if(wanted==count)return v;count++;}}return -1;}
}
