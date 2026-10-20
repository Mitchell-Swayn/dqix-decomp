#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void* MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov004 @ 0x021570F0; symbol: func_ov004_021570f0; size: 0x38.
extern "C" int Menu_GetListedPartyMemberIndex(int index) {
    if (index < 0)
        return -1;
    char* object = *(char**)((char*)&MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8);
    if (index >= *(short*)(object + 0x3a))
        return -1;
    return (signed char)*(short*)(object + 0x32 + index * 2);
}
