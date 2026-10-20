#include <globaldefs.h>
// Original: arm9/main @ 0x02083BC0; symbol: func_02083bc0; size: 0x28.
extern "C" unsigned CharacterState_GetLearnedSpellMask(const unsigned char *p, int bit) { return (p+bit/8)[0x910] & (1u << (bit%8)); }
