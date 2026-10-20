#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B1FB0; symbol: Unclassified_ReadByteAtOffset29; size: 0x8.
// Returns the unsigned byte at offset 0x29.
extern "C" unsigned int OnlineDownload_GetLegacyBossLevel(void *self) { return *((unsigned char *)self + 0x29); }
