#include <globaldefs.h>
ARM
extern "C" void CharacterState_CopyAttributePercentages(void*,void*);struct Bits{unsigned a:10,b:10,c:10,pad:2;};
// Original: arm9/main @ 0x02089560; symbol: func_02089560; size: 0xD0.
extern "C" void CombatantState_RefreshConfigurationForBattleEntry(unsigned char* object,unsigned char* source,unsigned char* config){object[0x25]=0;object[0x38]=0;CharacterState_CopyAttributePercentages(object+0x3e,source+9);*(unsigned short*)(object+12)=*(unsigned short*)(config+0x38);*(unsigned short*)(object+8)=*(unsigned short*)(config+0x34);*(unsigned short*)(object+10)=*(unsigned short*)(config+0x36);Bits* out=(Bits*)(object+16);Bits* in=(Bits*)(config+0x3c);out->a=(unsigned short)in->a;out->b=(unsigned short)in->b;out->c=(unsigned short)in->c;object[0x26]=1;}
