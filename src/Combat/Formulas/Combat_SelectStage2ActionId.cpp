#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(int,int);extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
inline int ReadStage(const unsigned char* p){return *p;}
struct Packed{unsigned low:10;unsigned first:10;unsigned second:10;unsigned high:2;};
// Original: arm9/ov024 @ 0x021E95D4; symbol: Combat_SelectStage2ActionId; size: 0x110.
extern "C" int Combat_SelectStage2ActionId(char* self,int index,char* entry,int mode,signed char delta,unsigned char special,unsigned char forced){
char* object=_Z16GetCombatantByIDii(*(int*)(self+16),index);if(!object)return 0;
if(special){if(!mode){switch(delta){case 2:return 58;case 0:return 62;default:return 60;}}else{switch(delta){case -2:return 59;case 0:return 62;default:return 61;}}}
if(mode==1){if(forced)return 31;if(*(unsigned char*)(*(char**)(self+16)+0x8e95)||ReadStage((unsigned char*)*(char**)(object+0x138)+80)<=0)return Combat_SelectMessageForPartyOrMonster(index,621,27);}
Packed* packed=(Packed*)(entry+36);return Combat_SelectMessageForPartyOrMonster(index,packed->first,packed->second);}
