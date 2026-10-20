#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int CombatEffect_TargetHasParalysis(LinkedDescriptorView*);
extern "C" bool CombatStatus_HasSleep(unsigned*);
struct Key{short value,pad;};struct Value{unsigned short value,pad;};
// Original data: arm9/ov024 @ 0x21fe7c4; symbol: data_ov024_021fe7c4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0200.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
// Original data: arm9/ov024 @ 0x21fe840; symbol: data_ov024_021fe840.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0200.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" Key CombatSelectCategoryMessageCode_UnknownRoleInitializedBytes_Variant3[],CombatSelectCategoryMessageCode_UnknownRoleInitializedBytes[];
// Original data: arm9/ov024 @ 0x21fe7c6; symbol: data_ov024_021fe7c6.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 23000300680004005b0006007b000700470108004d01ffffffff.
// Observed span: 26 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
// Original data: arm9/ov024 @ 0x21fe842; symbol: data_ov024_021fe842.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 24000300670004005c0006007c000700480108004e010900dc01ffffffff.
// Observed span: 30 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" Value CombatSelectCategoryMessageCode_UnknownRoleInitializedBytes_Variant4[],CombatSelectCategoryMessageCode_UnknownRoleInitializedBytes_Variant2[];
struct Category{unsigned short low:2,kind:4,high:10;};
// Original: arm9/ov024 @ 0x021E9018; symbol: func_ov024_021e9018; size: 0x180.
// Maps category codes through paired halfword tables, with party-specific code-five and descriptor-flag overrides.
extern "C" unsigned short Combat_SelectCategoryMessageCode(char* self,int index,int category,int alternate){
 if(alternate){if(category==5)return Combat_SelectMessageForPartyOrMonster(index,0x63,0x62);for(int i=0;CombatSelectCategoryMessageCode_UnknownRoleInitializedBytes_Variant3[i].value!=-1;i++){if(category==CombatSelectCategoryMessageCode_UnknownRoleInitializedBytes_Variant3[i].value)return CombatSelectCategoryMessageCode_UnknownRoleInitializedBytes_Variant4[i].value;}}
 else{
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),index);if(!object)return 0;
 if(CombatEffect_TargetHasParalysis((LinkedDescriptorView*)object)&&(category==3||category==4||category==5||category==8))return Combat_SelectMessageForPartyOrMonster(index,0x26d,0x1b);
 if(CombatStatus_HasSleep(*(unsigned**)(object+0x138))){short delta=category-2;if((unsigned short)delta<=6)return Combat_SelectMessageForPartyOrMonster(index,0x26d,0x1b);}
 unsigned kind=((Category*)(*(char**)(object+0x138)+0x22))->kind;
 if(kind!=category)return 0;
 if(kind==5)return Combat_SelectMessageForPartyOrMonster(index,0x61,0x60);
 for(int i=0;CombatSelectCategoryMessageCode_UnknownRoleInitializedBytes[i].value!=-1;i++){if(kind==CombatSelectCategoryMessageCode_UnknownRoleInitializedBytes[i].value)return CombatSelectCategoryMessageCode_UnknownRoleInitializedBytes_Variant2[i].value;}
 }
 return 0;
}
