#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);extern "C" float _ZNK6Script9Parameter7ToFloatEv(const void*);extern "C" char* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,void*);extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216BE6C; symbol: Script_QueueVectorAndThreeFixedPointComponents; size: 0xD4.
extern "C" int CombatScript_QueueVectorAndFixedPointScalars(char* parameter,int count){char* node=_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],40);W(node,0)=0;W(node,4)=0;W(node,0)=86;B(node,8)=_ZNK6Script9Parameter5ToIntEv(parameter);char* current=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(parameter+8,node+12);W(node,24)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(current));W(node,28)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(current+8));W(node,32)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(current+16));B(node,36)=0;if(count>=8)B(node,36)=_ZNK6Script9Parameter5ToIntEv(current+24);Overlay_EnqueueLinkedNode(node);return 1;}
