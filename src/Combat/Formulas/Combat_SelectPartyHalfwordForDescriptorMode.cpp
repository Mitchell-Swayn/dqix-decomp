#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" bool CombatStatus_HasSleep(void*);
extern "C" unsigned Combat_SelectMessageForPartyOrMonster(int,unsigned,unsigned);
// Original: arm9/ov024 @ 0x021E929C; symbol: Combat_SelectPartyHalfwordForDescriptorMode; size: 0x84.
// Selects party-index halfwords using descriptor mask 10 and the requested mode.
extern "C" unsigned Combat_SelectPartyHalfwordForDescriptorMode(char* self,int index,int mode) {
 char* combatant=_Z16GetCombatantByIDii(*(int*)(self+16),index);if(!combatant)return 0;
 bool flag=CombatStatus_HasSleep(*(void**)(combatant+0x138));
 if(mode){if(flag)return Combat_SelectMessageForPartyOrMonster(index,0x42,0x17e);return Combat_SelectMessageForPartyOrMonster(index,0x41,0x92);}
 if(flag)return 0x43;return Combat_SelectMessageForPartyOrMonster(index,0x26d,0x1b);
}
