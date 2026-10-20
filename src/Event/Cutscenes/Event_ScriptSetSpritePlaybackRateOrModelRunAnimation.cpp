#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" float Script_ReadParameterAsFloat(unsigned);
extern "C" unsigned Script_ReadParameterAsInteger(...);
extern "C" bool ActorSprite_SetPositiveAnimationPlaybackRate(unsigned,float);
extern "C" unsigned ActorSprite_SetMovingAnimationOverride(...);
extern "C" unsigned _ZN8Object3D18SetAnimationByNameEPKci(...);
extern "C" unsigned char Event_ScriptSetSpritePlaybackRateOrModelRunAnimation_TextRun[];
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x02160070; symbol: Script_SetRecordPositiveFloatOrRegularAnimation; size: 0xcc.
extern "C" int Event_ScriptSetSpritePlaybackRateOrModelRunAnimation(unsigned args){
int index=Script_ReadParameterAsInteger(args);float value=Script_ReadParameterAsFloat(args+8);struct Record {unsigned kind,unused[2],object;};Record* records=(Record*)U32(D(EventGetObjectSession_UnknownRoleZeroInitializedStorage)+4);unsigned table=D(records);unsigned kind=records[index].kind;
if(kind==2||kind==6){unsigned object=0;if(table)object=records[index].object;if(!object)return 0;unsigned nested=U32(object+0x14);if(nested)ActorSprite_SetMovingAnimationOverride(nested,1);nested=U32(object+0x14);if(nested)ActorSprite_SetPositiveAnimationPlaybackRate(nested,value);}
else if(kind==1||kind==0||(kind-4)<=1){unsigned object=0;if(table)object=records[index].object;if(!object)return 0;_ZN8Object3D18SetAnimationByNameEPKci(object,D(Event_ScriptSetSpritePlaybackRateOrModelRunAnimation_TextRun),0);}return 1;
}