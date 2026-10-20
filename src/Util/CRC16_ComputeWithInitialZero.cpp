#include <globaldefs.h>
ARM
extern "C" void CRC16_UpdateReflectedState(void*,unsigned short*,void*,unsigned);
// Original: arm9/main @ 0x020D1CC8; symbol: func_020d1cc8; size: 0x28.
extern "C" unsigned CRC16_ComputeWithInitialZero(void* table,void* data,unsigned count){unsigned short crc=0;CRC16_UpdateReflectedState(table,&crc,data,count);return crc;}
