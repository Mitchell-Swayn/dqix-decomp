#include <globaldefs.h>
extern "C" unsigned char* data_ov017_021d82e0[2];
extern "C" void WriteField55DFlagBitOrNibble(void*,unsigned,unsigned);
// Original: arm9/ov017 @ 0x0218B5C0; symbol: func_ov017_0218b5c0; size: 0x38.
extern "C" ARM void WriteCurrentNestedField55D(unsigned field,unsigned value) { unsigned char* object=data_ov017_021d82e0[1]; if(object && *(void**)(object+0x36d0)) WriteField55DFlagBitOrNibble(*(void**)(object+0x36d0),field,value); }
