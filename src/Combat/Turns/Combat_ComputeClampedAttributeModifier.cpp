#include <globaldefs.h>
ARM
extern "C" {
float _fadd(float,float);
void* _ZN9GameState11GetInstanceEv();
unsigned char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
int Ov000_TestNestedFlagBit3(void*);
int Combat_HasIncreasedStatusSusceptibility(void*);
int CombatStatus_HasAttributeWardModeOne(void*);
int CombatStatus_HasAttributeWardModeTwo(void*);
int CombatStatus_HasAttributeWardModeThree(char*);
int CombatStatus_HasAttributeWardModeFour(void*);
int CombatStatus_HasAttributeWardModeFive(void*);
}
struct AttributeRecord { char pad[0x3e]; unsigned char attributes[21]; };
inline unsigned char* AttributeData(AttributeRecord* p) { return p->attributes; }
// Original: arm9/ov000 @ 0x02156B38; symbol: func_ov000_02156b38; size: 0x15C.
extern "C" float Combat_ComputeClampedAttributeModifier(void*,int combatant,int attribute) {
 float a,b,c,d,e,modifier;
 unsigned char* p=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),combatant);
 if(!p) return 1.0f;
 modifier=0.0f;
 if(Ov000_TestNestedFlagBit3(p)) modifier=-25.0f;
 else if(Combat_HasIncreasedStatusSusceptibility(p)) modifier=25.0f;
 a=0.0f;
 if(CombatStatus_HasAttributeWardModeOne(*(void**)(p+0x138))) a=-50.0f;
 b=0.0f;
 if(CombatStatus_HasAttributeWardModeTwo(*(void**)(p+0x138))) b=-50.0f;
 c=0.0f;
 if(CombatStatus_HasAttributeWardModeThree(*(char**)(p+0x138))) c=-50.0f;
 d=0.0f;
 if(CombatStatus_HasAttributeWardModeFour(*(void**)(p+0x138))) d=-50.0f;
 e=0.0f;
 if(CombatStatus_HasAttributeWardModeFive(*(void**)(p+0x138))) e=-50.0f;
 unsigned char index=attribute-1;
 if(attribute<1 || attribute>21) return 1.0f;
 if(attribute==8) modifier=0.0f;
 else if(attribute>=1 && attribute<=7) {
  float adjustments[7]={a,b,c,c,d,d,e};
  modifier=adjustments[index];
 }
 float value=_fadd((float)(unsigned)AttributeData(*(AttributeRecord**)(p+0x138))[index],modifier);
 if(value<0.0f) value=0.0f;
 return value/100.0f;
}
