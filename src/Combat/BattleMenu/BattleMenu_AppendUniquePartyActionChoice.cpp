#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x021757AC; symbol: func_ov000_021757ac; size: 0x5C.
// Appends a halfword to the list at offset10 only if no existing entry matches.
extern "C" void BattleMenu_AppendUniquePartyActionChoice(char* self,int value) {
 bool found=false;
 unsigned short* entries=(unsigned short*)(self+0x10);
 signed char i=0;
 signed char count=self[0x1a];
 for(;i<count;i=(signed char)(i+1))if(value==entries[i])found=true;
 if(!found){self[0x1a]++;entries[count]=value;}
}
