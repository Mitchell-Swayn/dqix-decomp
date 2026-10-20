#include <globaldefs.h>
ARM
struct FloatParameterView;
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" { float Script_ReadParameterAsFloat(FloatParameterView*); void System_QueueAppendFourWordRecord(void*,int,int,int); extern unsigned char* EventGetObjectSession_UnknownRoleZeroInitializedStorage[]; }
// Original: arm9/ov001 @ 0x0215D608; symbol: func_ov001_0215d608; size: 0x7C.
extern "C" int Resource_DispatchThreeFixedPointScriptValues(unsigned char* parameters) {
 int y;
 int x=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)parameters));
 y=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameters+8)));
 int z=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameters+16)));
 System_QueueAppendFourWordRecord(EventGetObjectSession_UnknownRoleZeroInitializedStorage[9],x,y,z);
 return 1;
}
