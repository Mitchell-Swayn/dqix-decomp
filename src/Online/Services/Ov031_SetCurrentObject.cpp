#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2249b54; symbol: data_ov031_02249b54.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 709b24020000000000100000000000000000000000000000204e0000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NasAuthBuildAndStartHttpRequest_UnknownRoleDataReferences;
// Original: arm9/ov031 @ 0x022167A8; symbol: func_ov031_022167a8; size: 0x10.
extern "C" void Ov031_SetCurrentObject(unsigned int value) {
    NasAuthBuildAndStartHttpRequest_UnknownRoleDataReferences = value;
}
