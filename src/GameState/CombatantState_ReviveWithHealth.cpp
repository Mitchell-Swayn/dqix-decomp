#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0208902C; symbol: func_0208902c; size: 0x34.
extern "C" void CombatantState_ReviveWithHealth(unsigned char* p,unsigned short value) { unsigned int flags=*(unsigned int*)(p+0x14);bool enabled=false;if(flags&4)enabled=true;*(unsigned int*)(p+0x14)=0;*(unsigned int*)(p+0x18)=0;if(enabled)*(unsigned int*)(p+0x14)|=4;*(unsigned short*)p=value; }
