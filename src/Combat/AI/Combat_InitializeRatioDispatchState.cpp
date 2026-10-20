#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* GameState_GetObjectWithFlag100(void*,int);extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);extern "C" int GameState_SelectLowestRatioGroupObject(unsigned char**,int,int,short*);extern "C" void BattleAI_PrepareTurnActionEvaluation(void*);
// Original data: arm9/ov024 @ 0x21ff054; symbol: data_ov024_021ff054.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 44811f0200000000dc811f0200000000f0841f0200000000f8831f020000000000831f02.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct RatioDispatcher {void method(unsigned short,void*,void*);};typedef void(RatioDispatcher::*RatioHandler)(unsigned short,void*,void*);extern "C" RatioHandler CombatInitializeRatioDispatchState_UnknownRoleProcedureReferenceRecords[6];extern "C" RatioHandler ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021f8f20; symbol: Combat_InitializeRatioDispatchState; size 0x110.
extern "C" void Combat_InitializeRatioDispatchState(void* self,int owner,int index,unsigned short* input){void* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);void* state=GameObject_GetLinkedIndexedState(object);if(*input==1){W(self,0)=owner;S(self,4)=index;unsigned char mode=(signed char)W(state,0x94c);if(mode==5)return;if(mode>5){GameState_SelectLowestRatioGroupObject((unsigned char**)self,(unsigned short)index,(int)object,(short*)input);}else{W(self,0x124)=0x3f000000;B(self,6)=mode;BattleAI_PrepareTurnActionEvaluation(self);struct Handlers{RatioHandler p[6];};Handlers table=*(Handlers*)CombatInitializeRatioDispatchState_UnknownRoleProcedureReferenceRecords;table.p[5]=ShopUpdateInterface_UnknownRoleInitializedBytes;RatioHandler method=table.p[mode];if(method)(((RatioDispatcher*)self)->*method)((unsigned short)index,object,input);}}}
