#include <globaldefs.h>
ARM
#pragma force_active on
#pragma opt_common_subs off
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(void*,int);
extern "C" void Resource_UpdateSixColumnSelection(char*);
extern "C" void Graphics_UpdateSixEntryPageDisplay(char*);
extern "C" void Shop_RefreshPartyEquipmentComparisons(char*);
extern "C" void Graphics_ConfigureDisplayPartFromPartySum(char*);
extern "C" void Shop_RefreshPartyItemQuantities(char*);
// Original: arm9/ov003 @ 0x021785D4; symbol: func_ov003_021785d4; size: 0xE8.
// Wraps the purchase page and refreshes item details and party comparisons after page or selection changes.
extern "C" void Shop_UpdatePurchasePageAndComparisons(char* self)
{
    int step = 0;
    unsigned flags = *(unsigned*)(self + 0xfe4);
    if (flags & 0x10) {
        step = 1;
    } else if (flags & 0x20) {
        --step;
    }
    *(short*)(self + 0x1014) += step;
    if (*(short*)(self + 0x1016) <= *(short*)(self + 0x1014)) {
        *(short*)(self + 0x1014) = 0;
    }
    if (*(short*)(self + 0x1014) < 0) {
        *(short*)(self + 0x1014) = *(short*)(self + 0x1016) - 1;
    }
    if (step) {
        **(short**)(self + 0xff8) = FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(
            *(void**)(self + 0x89c), 3);
        Resource_UpdateSixColumnSelection(self);
        Graphics_UpdateSixEntryPageDisplay(self);
        Shop_RefreshPartyEquipmentComparisons(self);
        Graphics_ConfigureDisplayPartFromPartySum(self);
        Shop_RefreshPartyItemQuantities(self);
    }
    Resource_UpdateSixColumnSelection(self);
    if (*(short*)(self + 0x1000) != **(short**)(self + 0xff8)) {
        Graphics_UpdateSixEntryPageDisplay(self);
        Shop_RefreshPartyEquipmentComparisons(self);
        Graphics_ConfigureDisplayPartFromPartySum(self);
        Shop_RefreshPartyItemQuantities(self);
    }
}
