#include <globaldefs.h>
ARM
extern "C" int Combat_CollectLinkedRecordSideCombatants(void *object, void *target, unsigned int mode, unsigned int category, unsigned int *output);
// Original: arm9/ov000 @ 0x02181A8C; symbol: Unclassified_CollectPrimaryRecordIdsByIndex; size: 0x18.
// Selects the primary linked record by index and collects its matching IDs into the output array.
extern "C" int Combat_CollectPrimaryRecordOpposingCombatants(void *object, void *target, unsigned int *output) {
    return Combat_CollectLinkedRecordSideCombatants(object, target, 1, 0, output);
}
