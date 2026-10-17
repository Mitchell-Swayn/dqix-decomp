#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void ClearField18Flag8AndBytes6BAnd8E(void*);
// Original: arm9/main @ 0x02088D24; symbol: func_02088d24; size: 0x28.
extern "C" void Object_SetByte7BToFiveAndFlag10ThenUpdateState(unsigned char* p){p[123]=5;p[158]=0;*(unsigned*)(p+24)|=16;ClearField18Flag8AndBytes6BAnd8E(p);}
