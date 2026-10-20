#include <globaldefs.h>
// Original data: arm9/main @ 0x20fdc60; symbol: data_020fdc60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage[];
extern "C" void ResetModeDependentRecordValueAndCounter(void* record);
// Original: arm9/main @ 0x02027288; symbol: func_02027288; size: 0x7C.
extern "C" void PartyStatus_ResetMappedMemberAnimation(unsigned char* state, unsigned int index)
{
    if (static_cast<int>(index) < 0) {
        for (int i = 0; i < 4; ++i) {
            ResetModeDependentRecordValueAndCounter(PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage + i * 0x14);
        }
        return;
    }
    if (static_cast<int>(index) >= 4) return;
    for (int i = 0; i < 4; ++i) {
        unsigned char* entry = state + i;
        if (index == entry[0x758]) {
            ResetModeDependentRecordValueAndCounter(PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage + i * 0x14);
            return;
        }
    }
}
