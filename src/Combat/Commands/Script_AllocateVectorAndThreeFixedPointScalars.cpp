#include <globaldefs.h>
ARM
struct Vector3i { int x,y,z; };
struct Record { unsigned type,next; Vector3i vector; int a,b,c; };
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" char* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,Vector3i*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216BFA4; symbol: func_ov000_0216bfa4; size: 0xA8.
extern "C" int Script_AllocateVectorAndThreeFixedPointScalars(char* params) {
 Record* record=(Record*)_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],32);
 record->type=0;
 record->next=0;
 record->type=0x58;
 params=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(params,&record->vector);
 record->a=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(params));
 record->b=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(params+8));
 record->c=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(params+16));
 Overlay_EnqueueLinkedNode(record);
 return 1;
}
