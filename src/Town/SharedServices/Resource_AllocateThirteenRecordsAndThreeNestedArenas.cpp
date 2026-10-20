#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(...);
extern "C" void Graphics_InitializeSpriteTransformDefaults(...);
extern "C" void SpriteAnimation_ResetTrackList(...);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(...);
extern "C" void _ZN13SafeAllocator5ResetEv(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov003 @ 0x021726F8; symbol: Resource_AllocateThirteenRecordsAndThreeNestedArenas; size: 0xd0.
// Allocates thirteen forty-byte records, an output pair, and nested arenas of4096,10240,1024 bytes.
extern "C" void Resource_AllocateThirteenRecordsAndThreeNestedArenas(char* self,void* allocator){if(!allocator)return;P(self,0x1c0)=(char*)allocator;P(self,0x128)=_ZN13SafeAllocator8AllocateEj(allocator,520);P(self,0x12c)=_ZN13SafeAllocator8AllocateEj(P(self,0x1c0),8);for(int i=0;i<13;++i)Graphics_InitializeSpriteTransformDefaults(P(self,0x128)+40*i);SpriteAnimation_ResetTrackList(P(self,0x12c));_ZN13SafeAllocator11CreateTypeAEPvj(self+0x1ac,_ZN13SafeAllocator8AllocateEj(P(self,0x1c0),4096),4096);_ZN13SafeAllocator5ResetEv(self+0x1ac);_ZN13SafeAllocator11CreateTypeAEPvj(self+0x184,_ZN13SafeAllocator8AllocateEj(P(self,0x1c0),10240),10240);_ZN13SafeAllocator5ResetEv(self+0x184);_ZN13SafeAllocator11CreateTypeAEPvj(self+0x198,_ZN13SafeAllocator8AllocateEj(P(self,0x1c0),1024),1024);_ZN13SafeAllocator5ResetEv(self+0x198);}
