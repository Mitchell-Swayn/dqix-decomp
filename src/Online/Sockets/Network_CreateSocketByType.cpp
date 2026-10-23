#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x22496c4; symbol: data_ov031_022496c4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0001000000006604000000006108000000080c2000080d20.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkCreateSocketByType_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov031 @ 0x22496ac; symbol: data_ov031_022496ac.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0101c00501000000000000000000000800080c2000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkCreateSocketByType_UnknownRoleInitializedBytes[];
extern "C" void* RegisterObjectCallbackAndReturnObject(void *);
// Original: arm9/ov031 @ 0x022071D8; symbol: System_ConfigureCallbackRecordBySelector; size: 0x2C.
// Selects one of two static callback records by selector and passes the selected record to its handler.
extern "C" void Network_CreateSocketByType(int unused, int selector) {
    if (selector == 1)
        RegisterObjectCallbackAndReturnObject(NetworkCreateSocketByType_UnknownRoleInitializedBytes_Variant2);
    else
        RegisterObjectCallbackAndReturnObject(NetworkCreateSocketByType_UnknownRoleInitializedBytes);
}
