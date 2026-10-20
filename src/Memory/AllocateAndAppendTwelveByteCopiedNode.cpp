#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original data: arm9/main @ 0x214e33c; symbol: data_0214e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern SafeAllocator *LoadFileIntoMemory_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D78E0; symbol: func_020d78e0; size: 0x6C.
void AllocateAndAppendTwelveByteCopiedNode(char **p,void *record){while(*p)p=(char **)(*p+8);char *q=(char *)LoadFileIntoMemory_UnknownRoleZeroInitializedStorage[2]->Allocate(12);*p=q;if(!q)return;*(short *)q=-1;*(short *)(q+2)=-1;*(int *)(q+4)=0;*(int *)(q+8)=0;memcpy(*p,record,8);}
}
