#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_FindIndexedObjectWithFlag400(void*,unsigned);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" void CombatantState_ToggleAlternatingActionSelector(void*);
// Original data: arm9/ov000 @ 0x2182a6c; symbol: data_ov000_02182a6c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000010200000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
struct Eight{signed char bytes[8];};extern "C" Eight CombatSelectToggleResultForNonPartyIndex_UnknownRoleInitializedBytes;

inline int IsPartyIndex(int i){return i>=0&&i<=3;}
struct BitOne{unsigned char flag:1;unsigned char rest:7;};
inline int ChooseWhenZero(int value,int first,int second){if(value==0)return first;return second;}
// Original: arm9/ov000 @ 0x0215F57C; symbol: Combat_SelectToggleResultForNonPartyIndex; size: 0x100.
extern "C" int Combat_SelectToggleResultForNonPartyIndex(void* random,int index){
if(IsPartyIndex(index))return 0;
 char *object=GameState_FindIndexedObjectWithFlag400(_ZN9GameState11GetInstanceEv(),index);char *descriptor=*(char**)(object+0x138),*info=*(char**)(object+0x148);bool enabled=((BitOne*)(descriptor+0x3c))->flag!=0;
 int choice=_Z13NextRandomMaxP6Randomi(random,2);Eight values=CombatSelectToggleResultForNonPartyIndex_UnknownRoleInitializedBytes;
 values.bytes[1]=choice!=0;values.bytes[4]=enabled!=0;values.bytes[5]=ChooseWhenZero(enabled,0,2);values.bytes[6]=enabled?0:1;values.bytes[7]=ChooseWhenZero(enabled,2,0);
 int result=values.bytes[(*(unsigned*)(info+16)<<21)>>29];CombatantState_ToggleAlternatingActionSelector(*(void**)(object+0x138));return result;
}
