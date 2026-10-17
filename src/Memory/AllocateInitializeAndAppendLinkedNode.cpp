#include <globaldefs.h>
ARM
#include <Memory/SafeAllocator.h>
extern "C" void InitializeOwnerIndicesObjectAndEmbeddedState(void*);extern "C" int InitializeEmbeddedObjectAndFiveValues(void*,unsigned,SafeAllocator*,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x02057E6C; symbol: func_02057e6c; size: 0x94.
extern "C" int AllocateInitializeAndAppendLinkedNode(int* list,unsigned arg,SafeAllocator* allocator,unsigned a,unsigned b,unsigned c){unsigned char* node=(unsigned char*)allocator->Allocate(0x1f0);if(!node)return -1;InitializeOwnerIndicesObjectAndEmbeddedState(node);if(!InitializeEmbeddedObjectAndFiveValues(node,arg,allocator,a,b,c))return -1;int* tail=list;while(*tail)tail=(int*)(*tail+0x1ec);*tail=(int)node;int id=list[1];list[1]=id+1;return id;}
