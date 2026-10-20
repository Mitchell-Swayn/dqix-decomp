#include <globaldefs.h>
ARM
// Original: arm9/ov008 @ 0x02189284; symbol: func_02189284; size: 0xE8.
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void PartyTalk_AllocateProfileSessionResources(void *self,unsigned allocator) {
 char *base=(char*)self;
 char *p200=_ZN13SafeAllocator8AllocateEj(allocator,40960);
 _ZN13SafeAllocator11CreateTypeAEPvj(base+0x200,p200,40960);
 char *p214=_ZN13SafeAllocator8AllocateEj(allocator,3072);
 _ZN13SafeAllocator11CreateTypeAEPvj(base+0x214,p214,3072);
 char *p228=_ZN13SafeAllocator8AllocateEj(allocator,23552);
 _ZN13SafeAllocator11CreateTypeAEPvj(base+0x228,p228,23552);
 char *p23c=_ZN13SafeAllocator8AllocateEj(allocator,2048);
 _ZN13SafeAllocator11CreateTypeAEPvj(base+0x23c,p23c,2048);
 char *p250=_ZN13SafeAllocator8AllocateEj(allocator,9216);
 _ZN13SafeAllocator11CreateTypeAEPvj(base+0x250,p250,9216);
 char *p264=_ZN13SafeAllocator8AllocateEj(allocator,21504);
 _ZN13SafeAllocator11CreateTypeAEPvj(base+0x264,p264,21504);
 *(char**)(base+0x1f8)=_ZN13SafeAllocator8AllocateEj(allocator,0x140);
 *(char**)(base+0x1f4)=_ZN13SafeAllocator8AllocateEj(allocator,0x54);
 *(char**)(base+0x1fc)=_ZN13SafeAllocator8AllocateEj(allocator,8);
}
