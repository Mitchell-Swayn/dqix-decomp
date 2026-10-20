#include <globaldefs.h>
ARM
extern "C" unsigned int Network_GetConnectionPhase(void);
extern "C" void MI_CpuCopy8(const void *, void *, unsigned int);
// Original data: arm9/ov031 @ 0x224e5c4; symbol: data_ov031_0224e5c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02213054; symbol: CopyObjectRecordForOptionalModeRange; size: 0x58.
// When optional byte 9 is 10..16 and object subtype is 4 or 8, copies ten bytes from object +0x18 and returns true.
extern "C" int Network_CopyConnectionServiceIdentifier(void *out) {
    int result = 0;
    unsigned int value = Network_GetConnectionPhase();
    if (value >= 0xa && value <= 0x10) {
        unsigned char *object = *(unsigned char **)(NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage + 0xc);
        if (object[0x17] == 4 || object[0x17] == 8) {
            MI_CpuCopy8(object + 0x18, out, 0xa);
            result = 1;
        }
    }
    return result;
}
