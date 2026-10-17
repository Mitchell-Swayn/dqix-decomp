#include <globaldefs.h>
ARM
extern "C" void UpdateTableDrivenCRCOverBytes(const unsigned*,unsigned*,const void*,unsigned);
// Original: arm9/main @ 0x020D1CF0; symbol: func_020d1cf0; size: 0x2C.
extern "C" unsigned ComputeComplementedTableDrivenCRC(const unsigned* table,const void* data,unsigned size){unsigned crc=~0U;UpdateTableDrivenCRCOverBytes(table,&crc,data,size);return ~crc;}
