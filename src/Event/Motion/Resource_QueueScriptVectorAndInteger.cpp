#include <globaldefs.h>
ARM
struct FloatParameterView;struct IntegerParameterView;
struct FixedVector {int x,y,z;};
extern "C" void* memset(void*,int,unsigned);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void CutsceneCamera_QueueTimedTargetPosition(void*,FixedVector,unsigned);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215D418; symbol: func_ov001_0215d418; size: 0xA4.
extern "C" int Resource_QueueScriptVectorAndInteger(char* args) {
FixedVector vector;
memset(&vector,0,12);
vector.x=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)args));
vector.y=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+8)));
vector.z=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+16)));
unsigned value=Script_ReadParameterAsInteger((IntegerParameterView*)(args+24));
CutsceneCamera_QueueTimedTargetPosition(*(void**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+0x24),vector,value);
return 1;
}
