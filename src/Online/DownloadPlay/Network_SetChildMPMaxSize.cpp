#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e3424; symbol: data_ov027_021e3424.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern unsigned char IsGetAllRequestData_UnknownRoleZeroInitializedStorage[];
extern "C" int _s32_div_f(int, int);
// Original: arm9/ov027 @ 0x021DD5A4; symbol: func_ov027_021dd5a4; size: 0x30.
extern "C" void Network_SetChildMPMaxSize(int size) {
    int payloadSize = size - 2;
    *(int *)(IsGetAllRequestData_UnknownRoleZeroInitializedStorage + 8) = payloadSize;
    int slots = _s32_div_f(30, payloadSize);
    *(int *)(IsGetAllRequestData_UnknownRoleZeroInitializedStorage + 0xc) = slots;
    *(int *)(IsGetAllRequestData_UnknownRoleZeroInitializedStorage + 0x10) = 30;
}
