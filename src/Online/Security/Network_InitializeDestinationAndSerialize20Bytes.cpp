#include <globaldefs.h>
ARM
extern "C" void Crypto_UpdateSha1Context(void *, const void *, unsigned int);
extern "C" void Util_StoreWordsMostSignificantByteFirst(unsigned char *, const unsigned int *, unsigned int);
// Original data: arm9/ov031 @ 0x22498e5; symbol: data_ov031_022498e5.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.
// Observed span: 63 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char NetworkInitializeDestinationAndSerialize20Bytes_UnknownRoleInitializedBytes[];
// Original: arm9/ov031 @ 0x0220BA14; symbol: Network_InitializeDestinationAndSerialize20Bytes; size: 0x30.
// Initializes the destination from the 0x2c-byte template and serializes 0x14 bytes from it to the output.
extern "C" void Network_InitializeDestinationAndSerialize20Bytes(void *destination, unsigned int *source) {
    Crypto_UpdateSha1Context(destination, NetworkInitializeDestinationAndSerialize20Bytes_UnknownRoleInitializedBytes, 0x2c);
    Util_StoreWordsMostSignificantByteFirst((unsigned char *)source, (const unsigned int *)destination, 0x14);
}
