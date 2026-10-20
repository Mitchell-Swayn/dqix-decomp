#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218E174; symbol: Ov016_ReadWordAtOffset4; size: 0x8.
// Reads the 32-bit word at object offset 4. The object type is not established, so the ov016 prefix temporarily disambiguates this getter from another offset-4 getter.
extern "C" unsigned int MovieList_GetEntryCount(void* self) { return *(unsigned int*)((unsigned char*)self + 4); }
