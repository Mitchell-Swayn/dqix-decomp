#include <globaldefs.h>
ARM
#include <Memory/SignedAllocator.h>
extern "C" SignedAllocatorList data_0210f3d8;
// Original: arm9/main @ 0x020BC0A4; symbol: func_020bc0a4; size: 0x54.
extern "C" int CountAllocatorEntriesWithKindOneAndMatchingId(unsigned id){SignedAllocatorList* list;int count=0;SignedAllocatorHeader* entry=data_0210f3d8.ElementAfter(0);if(entry){list=&data_0210f3d8;do{char* p=(char*)entry;if(*(unsigned short*)(p+0x34)==1 && *(unsigned short*)(p+0x38)==id)++count;entry=list->ElementAfter(entry);}while(entry);}return count;}
