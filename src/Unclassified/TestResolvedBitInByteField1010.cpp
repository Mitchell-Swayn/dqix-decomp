#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
int Object_FindSignedByteKeyInSixteenEntries(void *);
// Original: arm9/main @ 0x0202C758; symbol: func_0202c758; size: 0x20.
unsigned int TestResolvedBitInByteField1010(unsigned char *p){int i=Object_FindSignedByteKeyInSixteenEntries(p);return p[0x1010]&(1u<<i);}
}
