#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" unsigned _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(void*);
// Original: arm9/ov013 @ 0x02184CF0; symbol: func_ov013_02184cf0; size: 0x90.
extern "C" void Memory_InitializeOptionalParentAndNestedAllocator(unsigned char* p,void* parent){
 if(!parent)return;
 if(p[0x640]){
 void* memory=_ZN13SafeAllocator8AllocateEj((unsigned)parent,0xc00);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x60c,memory,0xc00);
 }else{
 unsigned size=_ZNK13SafeAllocator24GetMaxPossibleAllocationEv(parent);
 void* memory=_ZN13SafeAllocator8AllocateEj((unsigned)parent,size);
 _ZN13SafeAllocator11CreateTypeAEPvj(p,memory,size);
 _ZN13SafeAllocator5ResetEv(p);
 memory=_ZN13SafeAllocator8AllocateEj((unsigned)p,0xc00);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x60c,memory,0xc00);
 }
}
