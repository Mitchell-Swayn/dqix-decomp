#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original: arm9/main @ 0x020E5850; symbol: func_020e5850; size: 0x2C.
void VideoCaptions_AllocateEntries(unsigned int *p,SafeAllocator *a,unsigned int count){void *data=a->Allocate(count*20);p[0]=(unsigned int)data;p[1]=count;p[2]=0;}
}
