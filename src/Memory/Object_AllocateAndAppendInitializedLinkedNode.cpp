#include "globaldefs.h"
#include "Memory/SafeAllocator.h"
#pragma optimize_for_size on
ARM
struct Node{unsigned char pad[0x1ec];Node*next;};struct List{Node*head;int count;};extern "C" void InitializeOwnerIndicesObjectAndEmbeddedState(Node*);extern "C" int Object3D_LoadCHRArchiveAndOptionalAuxiliaryResource(Node*,int,SafeAllocator*,void*,void*);
// Original: arm9/main @ 0x02057DE0; symbol: func_02057de0; size: 0x8C.
extern "C" int Object_AllocateAndAppendInitializedLinkedNode(List*p,int id,SafeAllocator*allocator,void*a,void*b){Node*n=(Node*)allocator->Allocate(0x1f0);if(!n)return -1;InitializeOwnerIndicesObjectAndEmbeddedState(n);if(!Object3D_LoadCHRArchiveAndOptionalAuxiliaryResource(n,id,allocator,a,b))return -1;Node**link=&p->head;while(*link)link=&(*link)->next;*link=n;return p->count++;}
