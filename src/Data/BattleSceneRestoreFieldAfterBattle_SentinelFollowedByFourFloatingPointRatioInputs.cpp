// Original data: arm9/ov000 @ 0x2183b0c; symbol: data_ov000_02183b0c.
// Sentinel followed by four floating-point ratio inputs. Static initializer0218381c reads float fields at offsets4..16.
// Initial values: hex ffffffff0000f041000034430000f04100003443.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
#include <globaldefs.h>
// Sentinel followed by four floating-point ratio inputs. Static initializer0218381c reads float fields at offsets4..16.
struct CombatRatioInputs { signed int sentinel; float ratios[4]; };
extern "C" {
CombatRatioInputs BattleSceneRestoreFieldAfterBattle_SentinelFollowedByFourFloatingPointRatioInputs = {-1, {30.0f, 180.0f, 30.0f, 180.0f}};
}
