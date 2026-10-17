#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original: arm9/main @ 0x02054EB4; symbol: func_02054eb4; size: 0x44.
bool AllocateAndClearThreeWords(unsigned int **p,SafeAllocator *a){if(!a)return false;unsigned int *q=(unsigned int *)a->Allocate(12);*p=q;if(!q)return false;q[0]=0;q[1]=0;q[2]=0;return true;}
}
