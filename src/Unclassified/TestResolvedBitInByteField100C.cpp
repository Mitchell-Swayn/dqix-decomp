#include <globaldefs.h>
ARM
extern "C" int Object_FindSignedByteKeyInSixteenEntries(void*,int);
// Original: arm9/main @ 0x0202C1C0; symbol: func_0202c1c0; size: 0x28.
extern "C" unsigned TestResolvedBitInByteField100C(unsigned char* p,int key){int bit=Object_FindSignedByteKeyInSixteenEntries(p,key);return bit<0?0:p[0x100c]&(1U<<bit);}
