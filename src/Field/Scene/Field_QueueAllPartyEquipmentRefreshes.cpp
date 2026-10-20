#include <globaldefs.h>
ARM
extern "C" void Field_QueuePartyMemberEquipmentRefresh(void*, int, int, int, int);
// Original: arm9/ov017 @ 0x0218F758; symbol: InitializeFourIndexedSlots; size: 0x44.
// Calls the slot initializer for indices 0 through 3 with all remaining values zero.
extern "C" void Field_QueueAllPartyEquipmentRefreshes(void* self) {
    for (int i = 0; i < 4; ++i) Field_QueuePartyMemberEquipmentRefresh(self, i, 0, 0, 0);
}
