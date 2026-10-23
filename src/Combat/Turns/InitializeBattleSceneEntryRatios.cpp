#include <globaldefs.h>
ARM
#pragma define_section init ".init" RX
extern "C" {
// Original data: arm9/ov000 @ 0x021838E8; symbol: data_ov000_021838e8.
extern float BattleScene_SaveFieldStateAndEnterBattle_StatusRecoveryRatioConstants[5];
// Original data: arm9/ov000 @ 0x0218423C; symbol: data_ov000_0218423c.
extern float BattleSceneSaveFieldStateAndEnterBattle_UnknownRoleZeroInitializedStorage[5];
}
// Original: arm9/ov000 @ 0x02183794; symbol: __sinit_ov000_02183794; size: 0x88.
// Initializes cumulative float ratios in the separately labelled overlay storage.
extern "C" __declspec(section "init") void __sinit_ov000_02183794()
{
    BattleSceneSaveFieldStateAndEnterBattle_UnknownRoleZeroInitializedStorage[4] = (BattleScene_SaveFieldStateAndEnterBattle_StatusRecoveryRatioConstants[3] + BattleScene_SaveFieldStateAndEnterBattle_StatusRecoveryRatioConstants[2]) + BattleScene_SaveFieldStateAndEnterBattle_StatusRecoveryRatioConstants[0] + BattleScene_SaveFieldStateAndEnterBattle_StatusRecoveryRatioConstants[1];
    float value = BattleSceneSaveFieldStateAndEnterBattle_UnknownRoleZeroInitializedStorage[0] + BattleScene_SaveFieldStateAndEnterBattle_StatusRecoveryRatioConstants[3];
    float middleIncrement = BattleScene_SaveFieldStateAndEnterBattle_StatusRecoveryRatioConstants[2];
    BattleSceneSaveFieldStateAndEnterBattle_UnknownRoleZeroInitializedStorage[3] = value;
    value += middleIncrement;
    float finalIncrement = BattleScene_SaveFieldStateAndEnterBattle_StatusRecoveryRatioConstants[0];
    BattleSceneSaveFieldStateAndEnterBattle_UnknownRoleZeroInitializedStorage[2] = value;
    value += finalIncrement;
    BattleSceneSaveFieldStateAndEnterBattle_UnknownRoleZeroInitializedStorage[1] = value;
}
