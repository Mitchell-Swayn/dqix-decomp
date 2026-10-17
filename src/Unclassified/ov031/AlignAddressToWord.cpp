#include <globaldefs.h>
// Rounds an address upward to the next four-byte boundary.
// Original: arm9/ov031 @ 0x022070BC; symbol: func_ov031_022070bc; size: 0xC.
extern "C" unsigned int AlignAddressToWord(unsigned int address) { return (address+3u)&~3u; }
