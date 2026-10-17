#include <globaldefs.h>
struct Arena { unsigned id; char allocator[0x1c]; };
struct Resources { char header[0x38]; char arena38[0x64]; char arena9c[0x28]; char arenac4[0x1c]; };
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" Resources* GameResources_GetInstance();
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021845f4(void*);
extern "C" Arena* func_ov011_021842c8(void*,unsigned);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void func_ov011_021842a0(Arena*);
extern "C" unsigned _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeBEPvji(void*,void*,unsigned,int);
extern "C" void func_ov011_02184324(void*,Arena*);
// Original: arm9/ov011 @ 0x02184DE4; symbol: func_ov011_02184de4; size: 0xEC.
extern "C" unsigned func_ov011_02184de4(void* self) {
 Resources* resources=GameResources_GetInstance();
 void* list=func_ov011_021845f4(func_ov017_021b2164());
 unsigned kind=func_ov011_02184c30(self);
 void* allocator;
 unsigned id=func_ov011_02184c30((char*)self+8);
 if(func_ov011_021842c8(list,id)) return 0;
 allocator=0;
 switch(kind) {
 case 0: allocator=resources->arena38; break;
 case 1: allocator=resources->arenac4; break;
 case 2: allocator=resources->arena9c; break;
 }
 if(!allocator) return 0;
 Arena* arena=(Arena*)_ZN13SafeAllocator8AllocateEj(allocator,sizeof(Arena));
 if(!arena) return 0;
 func_ov011_021842a0(arena);
 arena->id=id;
 unsigned size=_ZNK13SafeAllocator24GetMaxPossibleAllocationEv(allocator);
 void* memory=_ZN13SafeAllocator8AllocateEj(allocator,size);
 if(!memory) return 0;
 _ZN13SafeAllocator11CreateTypeBEPvji(arena->allocator,memory,size,4);
 func_ov011_02184324(list,arena);
 return 1;
}
