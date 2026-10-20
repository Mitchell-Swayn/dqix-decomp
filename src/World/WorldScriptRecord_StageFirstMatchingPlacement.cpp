#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2108fc8; symbol: data_02108fc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);extern "C" float _ZNK6Script9Parameter7ToFloatEv(const void*);extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);struct Vec{int x,y,z;};extern "C" void* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,Vec*);extern "C" char WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage[];extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x0208DAF4; symbol: Script_StageMatchingRecordWithStringVectorAndScalar; size: 0x10C.
extern "C" int WorldScriptRecord_StageFirstMatchingPlacement(char* parameter){if(W(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,0)==1)return 0;int type=_ZNK6Script9Parameter5ToIntEv(parameter);int first=_ZNK6Script9Parameter5ToIntEv(parameter+8);int second=_ZNK6Script9Parameter5ToIntEv(parameter+16);unsigned id=U(P(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,4),0);if(first!=id&&second!=id)return 0;B(P(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,8),0)=type;H(P(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,8),2)=first;H(P(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,8),42)=second;const char* string=_ZNK6Script9Parameter8ToStringEv(parameter+24);memcpy(P(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,8)+4,string,16);B(P(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,8),19)=0;B(P(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,8),20)=_ZNK6Script9Parameter5ToIntEv(parameter+32);*(float*)(P(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,8)+24)=_ZNK6Script9Parameter7ToFloatEv(parameter+40);void* next=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(parameter+48,(Vec*)(P(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,8)+28));H(P(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,8),40)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(next));W(WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage,0)=1;return 1;}
