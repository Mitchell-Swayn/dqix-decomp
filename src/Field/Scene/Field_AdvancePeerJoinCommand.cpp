#include <globaldefs.h>
ARM
struct PeerJoinCommand {
    unsigned char unknown_00;
    unsigned char complete;
    unsigned char unknown_02[6];
    unsigned char phase;
};
typedef int (*PeerJoinStep)(PeerJoinCommand*);
struct PeerJoinSteps { PeerJoinStep entries[5]; };
// Original data: arm9/ov017 @ 0x021D6AD8; procedure reference table (five entries).
extern "C" PeerJoinSteps FieldAdvancePeerJoinCommand_UnknownRoleProcedureReferenceRecords;
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_ClearFlags(void*, unsigned);
extern "C" void DisplayOverlay_ConfigureGlobalState(int, int, int, int);
#pragma force_active on
// Original: arm9/ov017 @ 0x021AEF0C; symbol: func_ov017_021aef0c; size: 0x74.
extern "C" void Field_AdvancePeerJoinCommand(PeerJoinCommand* command) {
    PeerJoinSteps steps = FieldAdvancePeerJoinCommand_UnknownRoleProcedureReferenceRecords;
    command->phase = steps.entries[command->phase](command);
    if (command->complete) {
        SystemState_ClearFlags(SystemState_GetGlobalFlags(), 0x800000);
        DisplayOverlay_ConfigureGlobalState(0, 1, 0, 1);
    }
}

#pragma force_active off
