#include <globaldefs.h>
ARM
extern "C" void QuestMenu_PopulateVisibleQuestRows(void *owner);
// Original: arm9/ov004 @ 0x02167424; symbol: Filesystem_BuildOwnerTaskGridAndReturnZero; size: 0x10.
// Builds the owner's task grid, then returns zero.
extern "C" int Filesystem_BuildOwnerTaskGridAndReturnZero(void *owner) {
    QuestMenu_PopulateVisibleQuestRows(owner);
    return 0;
}
