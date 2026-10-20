#include <globaldefs.h>
ARM
struct LinkedDescriptorView;struct ContextFlagOwner14;struct ContextFlagOwner30;struct ContextFlagOwner31;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);
extern "C" int Combatant_TestPrimaryStatusFlagBit27(ContextFlagOwner14*);
extern "C" int Combatant_TestPrimaryStatusFlagBit30(ContextFlagOwner30*);
extern "C" int Combatant_TestPrimaryStatusFlagBit31(ContextFlagOwner31*);
extern "C" int Combatant_HasFatalDamageProtection(unsigned char*);
extern "C" int Combatant_IsAilmentCategoryFour(void*);
extern "C" int Ov024_TestNestedByteEqualFive(void*);
extern "C" int Combatant_TestPrimaryStatusFlagBit28(LinkedDescriptorView*);
extern "C" int Combatant_TestPrimaryStatusFlagBit29(LinkedDescriptorView*);
extern "C" int Combatant_TestPrimaryStatusFlagBit26(LinkedDescriptorView*);
extern "C" int Combatant_TestPrimaryStatusFlagBit20(LinkedDescriptorView*);
extern "C" int Combatant_TestPrimaryStatusFlagBit21(LinkedDescriptorView*);
struct Nested {char pad[0x21];unsigned char kind;int IsOne(){return kind==1;}int IsTwo(){return kind==2;}};
// Original: arm9/ov024 @ 0x021EDA78; symbol: func_ov024_021eda78; size: 0x148.
// Tests the ordered preferred-target exclusion flags and categories; the final repeated flag query is preserved.
extern "C" int Combat_TestPreferredTargetExclusionFlags(int* self,int index){
 char* object=_Z16GetCombatantByIDii(*self,index);if(!object)return 0;
 if(Combatant_TestPrimaryStatusFlagBit9(object))return 1;
 if(Combatant_TestPrimaryStatusFlagBit27((ContextFlagOwner14*)object))return 1;
 if(((Nested*)*(void**)(object+0x138))->IsOne())return 1;
 if(((Nested*)*(void**)(object+0x138))->IsTwo())return 1;
 if(Combatant_TestPrimaryStatusFlagBit28((LinkedDescriptorView*)object))return 1;
 if(Combatant_TestPrimaryStatusFlagBit29((LinkedDescriptorView*)object))return 1;
 if(Combatant_TestPrimaryStatusFlagBit26((LinkedDescriptorView*)object))return 1;
 if(Combatant_TestPrimaryStatusFlagBit20((LinkedDescriptorView*)object))return 1;
 if(Combatant_TestPrimaryStatusFlagBit21((LinkedDescriptorView*)object))return 1;
 if(Combatant_HasFatalDamageProtection((unsigned char*)object))return 1;
 if(Combatant_TestPrimaryStatusFlagBit30((ContextFlagOwner30*)object))return 1;
 if(Combatant_TestPrimaryStatusFlagBit31((ContextFlagOwner31*)object))return 1;
 if(Combatant_IsAilmentCategoryFour(object))return 1;
 if(Ov024_TestNestedByteEqualFive(object))return 1;
 return Combatant_TestPrimaryStatusFlagBit20((LinkedDescriptorView*)object);
}
