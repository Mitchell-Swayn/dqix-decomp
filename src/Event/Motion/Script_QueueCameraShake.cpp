#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
struct V{int x,y,z;};extern "C" {float Script_ReadParameterAsFloat(void*);int Script_ReadParameterAsInteger(void*);extern char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];void CutsceneCamera_QueueEyeAndTargetShake(void*,V,int);}
// Original: arm9/ov001 @ 0x0215D8F4; symbol: QueueScriptFixedPointVectorAndIndex; size: 0x90.
// Reads three script floats into fixed12 vector and queues with fourth integer parameter.
extern "C" int Script_QueueCameraShake(char* script){V v;v.x=(int)(4096.0f*Script_ReadParameterAsFloat(script));v.y=(int)(4096.0f*Script_ReadParameterAsFloat(script+8));v.z=(int)(4096.0f*Script_ReadParameterAsFloat(script+16));int index=Script_ReadParameterAsInteger(script+24);CutsceneCamera_QueueEyeAndTargetShake(*(void**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+0x24),v,index);return 1;}
