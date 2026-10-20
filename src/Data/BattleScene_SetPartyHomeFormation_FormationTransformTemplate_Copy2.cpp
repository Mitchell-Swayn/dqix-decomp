// Original data: arm9/ov000 @ 0x21830e4; symbol: data_ov000_021830e4.
// Combat formation position/rotation vector template. Copied as a three-word coordinate value; exact fixed-point/angle units depend on the consuming setter.
// Observed values: hex 00000000cc00000000280000.
// Span: 12 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Combat formation position/rotation vector template. Copied as a three-word coordinate value; exact fixed-point/angle units depend on the consuming setter.
struct CombatCoordinate3 { signed int x, y, z; };
extern "C" {
extern const CombatCoordinate3 BattleScene_SetPartyHomeFormation_FormationTransformTemplate_Copy2 = {0, 204, 10240};
}
