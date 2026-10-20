#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original: arm9/main @ 0x02089EA0; symbol: func_02089ea0; size: 0x3C.
void CharacterTemplate_AllocateEntries(unsigned int *p,SafeAllocator *a,int count){if(!a||count<0)return;p[0]=(unsigned int)a->Allocate(count*64);((short *)p)[2]=0;((short *)p)[3]=count;}
}
