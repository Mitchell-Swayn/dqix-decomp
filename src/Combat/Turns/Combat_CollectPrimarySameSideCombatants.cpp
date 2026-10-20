#include <globaldefs.h>
ARM
extern "C" void Combat_CollectLinkedRecordSideCombatants(int, int, int, int, int);
// Original: arm9/ov000 @ 0x02181A5C; symbol: func_ov000_02181a5c; size: 0x18.
extern "C" void Combat_CollectPrimarySameSideCombatants(int a0, int a1, int a2) {
    Combat_CollectLinkedRecordSideCombatants(a0, a1, 1, 1, a2);
}
