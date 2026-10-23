#include <globaldefs.h>
ARM
struct ScanSelectionNibble { unsigned char value:4; unsigned char rest:4; };
extern "C" unsigned char Network_BuildSavedProfileScanTargets(void*);
extern "C" void MI_CpuCopy8(const void*, void*, unsigned);
// Original data: arm9/ov031 @ 0x02245FE0; symbol: data_ov031_02245fe0.
extern "C" char NetworkClassifyFreespotSsid_UnknownRoleInitializedBytes[];
// Original: arm9/ov031 @ 0x02214600; symbol: func_ov031_02214600; size: 0x60.
// Appends the eight-byte Freespot target for selection zero or six.
extern "C" unsigned Network_BuildFreespotScanTargets(void* workspace) {
    unsigned char* state = (unsigned char*)workspace;
    unsigned char* entry = state + 0x300;
    unsigned char count = Network_BuildSavedProfileScanTargets(state);
    entry += count * 36;
    if (((ScanSelectionNibble*)(state + 0xd0c))->value == 0 ||
        ((ScanSelectionNibble*)(state + 0xd0c))->value == 6) {
        MI_CpuCopy8(NetworkClassifyFreespotSsid_UnknownRoleInitializedBytes, entry + 4, 8);
        entry[3] = 8;
        entry[1] = 8;
        ++count;
    }
    return count;
}
