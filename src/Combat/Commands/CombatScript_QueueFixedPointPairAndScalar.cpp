#include <globaldefs.h>
ARM
extern "C" int Overlay_EnqueueLinkedNode(...);
extern "C" int _ZN13SafeAllocator8AllocateEj(...);
extern "C" int _ZNK6Script9Parameter5ToIntEv(...);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov000 @ 0x02169E80; symbol: ScriptQueueFixedPointCoordinatesAndValue.
extern "C" int CombatScript_QueueFixedPointPairAndScalar(char*parameter){
char*node=C(_ZN13SafeAllocator8AllocateEj(P(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage,8),16));W(node,0)=5;if(W(parameter,0)==2){float value=_ZNK6Script9Parameter7ToFloatEv(parameter);parameter+=8;H(node,8)=(int)(4096.0f*value);}else if(W(parameter,0)==1){int value=_ZNK6Script9Parameter5ToIntEv(parameter);parameter+=8;H(node,8)=(int)(4096.0f*((float)value/1000.0f));}if(W(parameter,0)==2){float value=_ZNK6Script9Parameter7ToFloatEv(parameter);parameter+=8;H(node,10)=(int)(4096.0f*value);}else if(W(parameter,0)==1){int value=_ZNK6Script9Parameter5ToIntEv(parameter);parameter+=8;H(node,10)=(int)(4096.0f*((float)value/1000.0f));}W(node,12)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(parameter));Overlay_EnqueueLinkedNode(node);return 1;
}
