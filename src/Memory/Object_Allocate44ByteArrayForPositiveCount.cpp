#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
extern "C" {
extern SafeAllocator *data_02109fe0;
// Original: arm9/main @ 0x020A8218; symbol: func_020a8218; size: 0x44.
void Object_Allocate44ByteArrayForPositiveCount(unsigned int *p,int valid,int count){if(!valid||!count)return;void *q=data_02109fe0->Allocate(count*44);*p=(unsigned int)q;((short *)p)[2]=count;((short *)p)[3]=0;}
}
