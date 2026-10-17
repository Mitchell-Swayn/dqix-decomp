#include <globaldefs.h>
ARM
struct State;struct SafeAllocator;struct Tree;
extern "C" void ResetRecordWithInvalidIndex(char*);
extern "C" Tree* FindTreeNodeForwarder(Tree*,unsigned);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Object_AllocateFiveSafeAllocatorsAndThreeEntries(State*,SafeAllocator*);
extern "C" void InitializeGraphicsStateAndEmbeddedResources(unsigned char*,unsigned char);
// Original: arm9/ov004 @ 0x02167820; symbol: func_ov004_02167820; size: 0x9C.
extern "C" int Graphics_InitializeType15RecordResources(unsigned char* p,Tree* owner,int id,int kind){
 ResetRecordWithInvalidIndex((char*)p);
 *(unsigned short*)(p+4)=0x15;
 *(unsigned short*)(p+6)=id;
 *(unsigned short*)(p+8)=kind;
 *(int*)(p+0x1c)=2;
 unsigned char* node=(unsigned char*)FindTreeNodeForwarder(owner,*(unsigned short*)(p+8));
 if(!node)return 0;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x20);
 void* memory=_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),0x2800);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x20,memory,0x2800);
 InitializeGraphicsStateAndEmbeddedResources(p+0x34,1);
 Object_AllocateFiveSafeAllocatorsAndThreeEntries((State*)(p+0x34),(SafeAllocator*)(p+0x20));
 *(unsigned short*)(p+0x106)=9999;
 return 1;
}
