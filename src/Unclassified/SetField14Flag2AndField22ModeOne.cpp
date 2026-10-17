#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088624; symbol: func_02088624; size: 0x20.
extern "C" void SetField14Flag2AndField22ModeOne(unsigned char* p) { *(unsigned int*)(p+0x14)|=2; *(unsigned short*)(p+0x22)=(*(unsigned short*)(p+0x22)&~3)|1; }
