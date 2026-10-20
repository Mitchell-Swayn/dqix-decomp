#include <globaldefs.h>
ARM
struct Parameter {int type;float value;};
struct Vector3i {int x,y,z;};
extern "C" void* memset(void*,int,unsigned);
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
struct FloatParameterView;
extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);
extern "C" char* Event_GetObjectSession(int);
extern "C" void CutsceneCamera_QueueFollowActorWithOffset(void*,void*,Vector3i);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov001 @ 0x0215DFC4; symbol: Script_OffsetSelectedRecordByThreeOptionalFloatParameters; size: 0xFC.
extern "C" int Script_QueueCameraTargetTracking(Parameter* params,int count){char* record=Event_GetObjectSession(Script_ReadParameterAsInteger((IntegerParameterView*)params++));if(!record)return 0;Vector3i value;memset(&value,0,12);if(count>=2){value.x+=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)params++));;}if(count>=3){value.y+=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)params++));;}if(count>=4)value.z+=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)params));CutsceneCamera_QueueFollowActorWithOffset(P(EventGetObjectSession_UnknownRoleZeroInitializedStorage,36),record,value);return 1;}