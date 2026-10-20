#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B1FA8; symbol: Unclassified_ReadByteAtOffset28; size: 0x8.
// Returns the unsigned byte at offset 0x28.
extern "C" unsigned int OnlineDownload_GetLegacyBossId(void *self) { return *((unsigned char *)self + 0x28); }
