#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020D1C64; symbol: func_020d1c64; size: 0x3C.
void UpdateTableDrivenCRCOverBytes(unsigned int *table,unsigned int *result,unsigned char *data,unsigned int n){unsigned int crc=*result;unsigned int i=0;if(i<n)do{unsigned int v=*data++;i++;crc=table[(crc^v)&255]^(crc>>8);}while(i<n);*result=crc;}
}
