#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x22496fc; symbol: data_ov031_022496fc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 04000500ffffffff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int SslSendClientHello_UnknownRoleInitializedBytes[];
// Original: arm9/ov031 @ 0x02207CE0; symbol: func_ov031_02207ce0; size: 0x10.
extern "C" void Ssl_SetCryptoThreadPriority(unsigned int value) { SslSendClientHello_UnknownRoleInitializedBytes[1] = value; }
