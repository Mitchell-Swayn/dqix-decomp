#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
// Original: arm9/main @ 0x020BC658; symbol: func_020bc658; size: 0x50.
extern "C" void InsertAllocatorEntryByByteRank(SignedAllocatorList* list,SignedAllocatorHeader* entry) {SignedAllocatorHeader* p=list->ElementAfter(0);if(p) do {if(*((unsigned char*)entry+0x3d)<*((unsigned char*)p+0x3d))break;p=list->ElementAfter(p);} while(p);list->InsertBefore(p,entry);*(SignedAllocatorList**)((char*)entry+4)=list;}
