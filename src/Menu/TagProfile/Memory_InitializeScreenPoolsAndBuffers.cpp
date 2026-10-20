#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void InitializeBufferHeaderAndStatusBytes(void*);
extern "C" void TextEntry_InitializeControlAndGridTables(void*);
extern "C" int GameState_CopyCollectionFlagBitset(void*);
// Original: arm9/ov012 @ 0x02184884; symbol: func_ov012_02184884; size: 0x248.
extern "C" void Memory_InitializeScreenPoolsAndBuffers(char* self,unsigned allocator) {
 if(!allocator) return;
 *(char**)self=_ZN13SafeAllocator8AllocateEj(allocator,40);
 if(*(char**)self) InitializeBufferHeaderAndStatusBytes(*(char**)self);
 *(char**)(self+4)=_ZN13SafeAllocator8AllocateEj(allocator,16);
 if(*(char**)(self+4)) TextEntry_InitializeControlAndGridTables(*(char**)(self+4));
 _ZN13SafeAllocator11CreateTypeAEPvj(self+32,_ZN13SafeAllocator8AllocateEj(allocator,84992),84992);
 _ZN13SafeAllocator11CreateTypeAEPvj(self+52,_ZN13SafeAllocator8AllocateEj(allocator,9216),9216);
 _ZN13SafeAllocator11CreateTypeAEPvj(self+72,_ZN13SafeAllocator8AllocateEj(allocator,37888),37888);
 _ZN13SafeAllocator11CreateTypeAEPvj(self+92,_ZN13SafeAllocator8AllocateEj(allocator,2048),2048);
 _ZN13SafeAllocator11CreateTypeAEPvj(self+112,_ZN13SafeAllocator8AllocateEj(allocator,6144),6144);
 _ZN13SafeAllocator11CreateTypeAEPvj(self+132,_ZN13SafeAllocator8AllocateEj(allocator,21504),21504);
 _ZN13SafeAllocator11CreateTypeAEPvj(self+152,_ZN13SafeAllocator8AllocateEj(allocator,1024),1024);
 *(char**)(self+4964)=_ZN13SafeAllocator8AllocateEj(allocator,760);
 *(char**)(self+4956)=_ZN13SafeAllocator8AllocateEj(allocator,84);
 *(char**)(self+4960)=_ZN13SafeAllocator8AllocateEj(allocator,8);
 *(char**)(self+4972)=_ZN13SafeAllocator8AllocateEj(allocator,120);
 *(char**)(self+4968)=_ZN13SafeAllocator8AllocateEj(allocator,84);
 *(char**)(self+5036)=_ZN13SafeAllocator8AllocateEj(allocator,114);
 *(char**)(self+5044)=_ZN13SafeAllocator8AllocateEj(allocator,15360);
 *(char**)(self+5052)=_ZN13SafeAllocator8AllocateEj(allocator,242);
 memset(*(char**)(self+5052),0,242);
 *(char**)(self+5056)=_ZN13SafeAllocator8AllocateEj(allocator,18);
 memset(*(char**)(self+5056),0,18);
 *(char**)(self+5064)=_ZN13SafeAllocator8AllocateEj(allocator,908);
 memset(*(char**)(self+5064),0,908);
 *(char**)(self+5068)=_ZN13SafeAllocator8AllocateEj(allocator,60);
 memset(*(char**)(self+5068),0,60);
 GameState_CopyCollectionFlagBitset(*(void**)(self+0x13cc));
 *(char**)(self+5072)=_ZN13SafeAllocator8AllocateEj(allocator,1024);
 memset(*(char**)(self+5072),0,1024);
}
