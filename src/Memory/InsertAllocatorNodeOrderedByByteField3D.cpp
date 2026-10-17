#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
extern "C" SignedAllocatorList data_0210f3d8;
// Original: arm9/main @ 0x020BC6A8; symbol: func_020bc6a8; size: 0x54.
extern "C" ARM void InsertAllocatorNodeOrderedByByteField3D(SignedAllocatorHeader* what){SignedAllocatorHeader* p=data_0210f3d8.ElementAfter(0);if(p){SignedAllocatorList* list=&data_0210f3d8;do{if(((unsigned char*)what)[0x3d]<((unsigned char*)p)[0x3d])break;p=list->ElementAfter(p);}while(p);}data_0210f3d8.InsertBefore(p,what);}
