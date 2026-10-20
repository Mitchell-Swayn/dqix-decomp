#include <globaldefs.h>
extern "C" void CRC8_UpdateWithLookupTable(const unsigned char*,unsigned char*,const unsigned char*,unsigned);
// Original: arm9/main @ 0x020D1CA0; symbol: func_020d1ca0; size: 0x28.
extern "C" ARM unsigned char CRC_ComputeEightBitStateStartingAtZero(const unsigned char* table,const unsigned char* data,unsigned size){unsigned char crc=0;CRC8_UpdateWithLookupTable(table,&crc,data,size);return crc;}
