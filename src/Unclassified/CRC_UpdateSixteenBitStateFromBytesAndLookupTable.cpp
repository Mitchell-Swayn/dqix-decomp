#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020D1BE4; symbol: func_020d1be4; size: 0x40.
void CRC_UpdateSixteenBitStateFromBytesAndLookupTable(unsigned short *table,unsigned short *crc,unsigned char *data,unsigned int len){unsigned int state=*crc;unsigned int i=0;if(i<len)do{unsigned int b=*data++;i++;state=table[((state^b)<<24)>>24]^(state>>8);}while(i<len);*crc=state;}
}
