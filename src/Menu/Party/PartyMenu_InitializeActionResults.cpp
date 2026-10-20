#include <globaldefs.h>
struct Record {
    unsigned char first;
    unsigned char pad;
    unsigned short middle;
    unsigned char last;
};
struct SelectionAction {
    short action;
    signed char actor;
    unsigned char mode;
    signed char targets[4];
    Record firstRecords[4];
    Record secondRecords[4];
    unsigned flags;
};
extern "C" void PartyMenu_ClearTargetActionResult(Record*);
// Original: arm9/ov002 @ 0x02157CE0; symbol: func_ov002_02157ce0; size: 0x60.
// Initializes the action header, four target sentinels, paired records, and trailing flags.
extern "C" void PartyMenu_InitializeActionResults(SelectionAction* action) {
    action->action = 0;
    action->actor = -1;
    action->mode = 0;
    for (int i = 0; i < 4; ++i) {
        action->targets[i] = -1;
        PartyMenu_ClearTargetActionResult(&action->firstRecords[i]);
        PartyMenu_ClearTargetActionResult(&action->secondRecords[i]);
    }
    action->flags = 0;
}
