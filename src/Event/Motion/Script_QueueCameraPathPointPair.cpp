#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
struct FloatParameterView;extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);extern "C" void* memset(void*,int,unsigned);extern "C" void AllocateAndCopySixWordsToNode(void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);extern "C" unsigned EventGetObjectSession_UnknownRoleZeroInitializedStorage[];struct Vec{int x,y,z;};
// Original: arm9/ov001 @ 0x0215D7A8; symbol: Script_AllocateNodeFromSixFixedPointCoordinates; size: 0x10C.
extern "C" int Script_QueueCameraPathPointPair(char* parameter){Vec first,second;memset(&first,0,12);memset(&second,0,12);first.x=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)parameter));first.y=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameter+8)));first.z=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameter+16)));second.x=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameter+24)));second.y=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameter+32)));second.z=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameter+40)));((void(*)(void*,Vec,Vec))AllocateAndCopySixWordsToNode)((void*)EventGetObjectSession_UnknownRoleZeroInitializedStorage[9],first,second);return 1;}
