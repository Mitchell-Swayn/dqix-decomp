#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
signed char *Inventory_GetGroupQuantities(void *,int);unsigned int Inventory_GetGroupCapacity(void *,int);
// Original: arm9/main @ 0x0207C72C; symbol: func_0207c72c; size: 0x74.
int Inventory_GetNthPositiveQuantity(void *p,int i,int wanted){signed char *q=Inventory_GetGroupQuantities(p,i);if(!q)return 0;short count=0;unsigned int n=Inventory_GetGroupCapacity(p,i);for(unsigned int j=0;j<n;q++,j++){int v=*q;if(v>0){if(wanted==count)return v;count++;}}return 0;}
}
