#include <globaldefs.h>
ARM
extern "C" void* _Z16GetCombatantByIDii(int,int);
// Original: arm9/ov024 @ 0x021E9904; symbol: Combat_SelectMessageForModeAndSignedResult; size: 0x8c.
// Maps mode and signed result to message values after verifying combatant exists.
extern "C" unsigned Combat_SelectMessageForModeAndSignedResult(char* self,int index,int unused,int mode,volatile signed char result) {
 if(!_Z16GetCombatantByIDii(*(int*)(self+16),index))return 0;
 if(mode==0){switch(result){case 2:return 0xd0;case 0:return 0x1b7;default:return 0xd1;}}
 else {switch(result){case -2:return 0x1b6;case 0:return 0x1b7;default:return 0x1b5;}}
}
