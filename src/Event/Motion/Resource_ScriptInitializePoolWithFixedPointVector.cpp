#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};struct FloatParameterView;struct IntegerParameterView;
extern "C" void* memset(void*,int,unsigned);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void Pool_InitializeConfiguredNode(void*,Vec,unsigned);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215D4BC; symbol: func_ov001_0215d4bc; size: 0xA4.
extern "C" int Resource_ScriptInitializePoolWithFixedPointVector(unsigned char* p){
 Vec v;memset(&v,0,12);
 v.x=4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)p);
 v.y=4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(p+8));
 v.z=4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(p+16));
 int mode=Script_ReadParameterAsInteger((IntegerParameterView*)(p+24));
 Pool_InitializeConfiguredNode(*(void**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+0x24),v,mode);
 return 1;
}
