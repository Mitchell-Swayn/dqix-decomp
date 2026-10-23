#include <globaldefs.h>
ARM
#pragma define_section init ".init" RX
struct CombatRatioInputs { signed int sentinel; float ratios[4]; };
extern "C" {
// Original data: arm9/ov000 @ 0x02183B0C; symbol: data_ov000_02183b0c.
// Initial values: sentinel -1; ratios 30, 180, 30, 180.
extern CombatRatioInputs BattleSceneRestoreFieldAfterBattle_SentinelFollowedByFourFloatingPointRatioInputs;
// Original data: arm9/ov000 @ 0x02184250; symbol: data_ov000_02184250.
extern float SinitOv0000218381C_UnknownRoleZeroInitializedStorage[5];
}
// Original: arm9/ov000 @ 0x0218381C; symbol: __sinit_ov000_0218381c; size: 0x88.
// Initializes cumulative float ratios in the separately labelled overlay storage.
extern "C" __declspec(section "init") void __sinit_ov000_0218381c()
{
    SinitOv0000218381C_UnknownRoleZeroInitializedStorage[4] = (BattleSceneRestoreFieldAfterBattle_SentinelFollowedByFourFloatingPointRatioInputs.ratios[3] + BattleSceneRestoreFieldAfterBattle_SentinelFollowedByFourFloatingPointRatioInputs.ratios[2]) + BattleSceneRestoreFieldAfterBattle_SentinelFollowedByFourFloatingPointRatioInputs.ratios[1] + BattleSceneRestoreFieldAfterBattle_SentinelFollowedByFourFloatingPointRatioInputs.ratios[0];
    float value = SinitOv0000218381C_UnknownRoleZeroInitializedStorage[3] + BattleSceneRestoreFieldAfterBattle_SentinelFollowedByFourFloatingPointRatioInputs.ratios[3];
    float middleIncrement = BattleSceneRestoreFieldAfterBattle_SentinelFollowedByFourFloatingPointRatioInputs.ratios[2];
    SinitOv0000218381C_UnknownRoleZeroInitializedStorage[2] = value;
    value += middleIncrement;
    float finalIncrement = BattleSceneRestoreFieldAfterBattle_SentinelFollowedByFourFloatingPointRatioInputs.ratios[1];
    SinitOv0000218381C_UnknownRoleZeroInitializedStorage[1] = value;
    value += finalIncrement;
    SinitOv0000218381C_UnknownRoleZeroInitializedStorage[0] = value;
}
