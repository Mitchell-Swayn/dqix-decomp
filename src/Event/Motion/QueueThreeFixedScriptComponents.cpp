#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct Components{int x,y,z;};
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" float Script_ReadParameterAsFloat(void*);extern "C" void* EventGetObjectSession_UnknownRoleZeroInitializedStorage[];extern "C" void System_QueueAndCopyThreeWords(void*,Components);
// Original: arm9/ov001 @ 0x0215D19C; symbol: QueueThreeFixedScriptComponents; size: 0x98.
// Scales three script floats by4096 and queues their three fixed-point words.
extern "C" int QueueThreeFixedScriptComponents(char* parameters){Components value;memset(&value,0,12);value.x=(int)(4096.0f*Script_ReadParameterAsFloat(parameters));value.y=(int)(4096.0f*Script_ReadParameterAsFloat(parameters+8));value.z=(int)(4096.0f*Script_ReadParameterAsFloat(parameters+16));System_QueueAndCopyThreeWords(EventGetObjectSession_UnknownRoleZeroInitializedStorage[9],value);return 1;}
