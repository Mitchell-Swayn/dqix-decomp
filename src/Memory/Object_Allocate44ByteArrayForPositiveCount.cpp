#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original data: arm9/main @ 0x2109fe0; symbol: data_02109fe0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern SafeAllocator *ObjectAllocate44ByteArrayForPositiveCount_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020A8218; symbol: func_020a8218; size: 0x44.
void Object_Allocate44ByteArrayForPositiveCount(unsigned int *p,int valid,int count){if(!valid||!count)return;void *q=ObjectAllocate44ByteArrayForPositiveCount_UnknownRoleZeroInitializedStorage->Allocate(count*44);*p=(unsigned int)q;((short *)p)[2]=count;((short *)p)[3]=0;}
}
