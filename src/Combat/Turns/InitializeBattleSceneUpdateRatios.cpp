#include <globaldefs.h>
ARM
#pragma define_section init ".init" RX
extern "C" {
// Original data: arm9/ov000 @ 0x021838C8; symbol: data_ov000_021838c8.
extern float ProgramData_StatusRecoveryRatioConstants[4];
// Original data: arm9/ov000 @ 0x02184220; symbol: data_ov000_02184220.
extern float BattleSceneUpdate_UnknownRoleZeroInitializedStorage[7];
}
// Original: arm9/ov000 @ 0x02183710; symbol: __sinit_ov000_02183710; size: 0x84.
// Initializes cumulative float ratios in the separately labelled overlay storage.
extern "C" __declspec(section "init") void __sinit_ov000_02183710()
{
    BattleSceneUpdate_UnknownRoleZeroInitializedStorage[6] = (ProgramData_StatusRecoveryRatioConstants[0] + ProgramData_StatusRecoveryRatioConstants[1]) + ProgramData_StatusRecoveryRatioConstants[3] + ProgramData_StatusRecoveryRatioConstants[2];
    float value = BattleSceneUpdate_UnknownRoleZeroInitializedStorage[5] + ProgramData_StatusRecoveryRatioConstants[0];
    float middleIncrement = ProgramData_StatusRecoveryRatioConstants[1];
    BattleSceneUpdate_UnknownRoleZeroInitializedStorage[4] = value;
    value += middleIncrement;
    float finalIncrement = ProgramData_StatusRecoveryRatioConstants[3];
    BattleSceneUpdate_UnknownRoleZeroInitializedStorage[3] = value;
    value += finalIncrement;
    BattleSceneUpdate_UnknownRoleZeroInitializedStorage[2] = value;
}
