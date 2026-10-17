#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
extern SignedAllocatorList data_0210f3d8;
extern "C" void InsertAllocatorEntryByByteRank(SignedAllocatorList*,SignedAllocatorHeader*); extern "C" void InsertAllocatorNodeOrderedByByteField3D(SignedAllocatorHeader*);
// Original: arm9/main @ 0x020BC870; symbol: func_020bc870; size: 0x60.
extern "C" void ChangeEntryRankAndReinsertInOwnerList(SignedAllocatorHeader* p,unsigned char rank) { SignedAllocatorList* parent=*(SignedAllocatorList**)((char*)p+4); if(parent){parent->Remove(p); *(SignedAllocatorList**)((char*)p+4)=0;} data_0210f3d8.Remove(p); *((unsigned char*)p+61)=rank; if(parent)InsertAllocatorEntryByByteRank(parent,p); InsertAllocatorNodeOrderedByByteField3D(p); }
