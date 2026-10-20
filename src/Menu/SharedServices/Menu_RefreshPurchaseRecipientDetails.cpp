#include <globaldefs.h>
ARM
extern "C" void PopulateEightSelectedObjectRecordLabels(void *);
extern "C" void Menu_RefreshPurchaseEquipmentComparison(void *);
// Original: arm9/ov004 @ 0x02159FB0; symbol: DispatchObjectCallbacksAndUpdateRecordState; size: 0x1C.
// Runs the object callback processing routine followed by serialized primary-record update processing.
extern "C" int Menu_RefreshPurchaseRecipientDetails(void *p) {
    PopulateEightSelectedObjectRecordLabels(p);
    Menu_RefreshPurchaseEquipmentComparison(p);
    return 0;
}
