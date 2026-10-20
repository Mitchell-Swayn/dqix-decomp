#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" void OSi_ReferSymbol(const void *);
// Original: arm9/ov031 @ 0x0220AA68; symbol: Object_SetNestedByte9FromInput; size: 0x30.
// Follows the global object pointers and, when the nested object exists, stores the input byte at nested offset +9.
extern "C" void Ssl_SetCurrentSocketHandshakeTimeoutEnabled(unsigned char value) {
    OSi_ReferSymbol((const void *)0x02000c44);
    unsigned char *object = *(unsigned char **)(OSInitThread_UnknownRoleZeroInitializedStorage_Variant2 + 4);
    object = *(unsigned char **)(object + 0xa4);
    if (object != 0)
        object[9] = value;
}
