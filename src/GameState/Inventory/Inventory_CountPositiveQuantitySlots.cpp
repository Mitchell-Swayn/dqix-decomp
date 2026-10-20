#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
signed char *Inventory_GetGroupQuantities(void *,int);int Inventory_GetGroupCapacity(void *,int);
// Original: arm9/main @ 0x0207C638; symbol: func_0207c638; size: 0x5C.
short Inventory_CountPositiveQuantitySlots(void *p,int i){signed char *q=Inventory_GetGroupQuantities(p,i);int n=Inventory_GetGroupCapacity(p,i);short count=0;for(short j=0;j<n;j++)if(q[j]>0)count++;return count;}
}
