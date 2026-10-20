#include <globaldefs.h>
ARM
extern "C" void Combat_CollectLinkedRecordSideCombatants(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov000 @ 0x02181A74; symbol: Unclassified_CollectSecondaryRecordIdsByIndex; size: 0x18.
// Selects the secondary linked record by index and collects its matching IDs into the output array.
extern "C" void Combat_CollectSecondarySameSideCombatants(unsigned int a, unsigned int b, unsigned int c) {
    Combat_CollectLinkedRecordSideCombatants(a, b, 0, 1, c);
}
