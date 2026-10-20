#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct Resource{unsigned kind:12,length:19,owned:1;void* first;void* second;};extern "C" void* memcpy(void*,const void*,unsigned);extern "C" unsigned ExperienceAdjustment_GetThresholdSectionSize(void*);extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
// Original: arm9/ov023 @ 0x021F5448; symbol: AllocateAndCopyTwoPackedResourceSections; size: 0xDC.
extern "C" int ExperienceAdjustment_CopyTableSections(Resource* self,void* allocator,const char* source,int enabled){if(!allocator||!source||!enabled)return 0;if(allocator&&source){memcpy(self,source,4);unsigned first=ExperienceAdjustment_GetThresholdSectionSize(self);unsigned second=self->length;if(first)self->first=_ZN13SafeAllocator8AllocateEj(allocator,first);else self->first=0;self->second=second?_ZN13SafeAllocator8AllocateEj(allocator,second):0;if(self->first)memcpy(self->first,source+4,first);if(self->second)memcpy(self->second,source+(ExperienceAdjustment_GetThresholdSectionSize(self)+4),second);self->owned=1;}return 1;}
