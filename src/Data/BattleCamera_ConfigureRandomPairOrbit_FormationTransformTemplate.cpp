// Original data: arm9/ov000 @ 0x2183274; symbol: data_ov000_02183274.
// Combat formation position/rotation vector template. Copied as a three-word coordinate value; exact fixed-point/angle units depend on the consuming setter.
// Observed values: hex 000000000010000000000000.
// Span: 12 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Combat formation position/rotation vector template. Copied as a three-word coordinate value; exact fixed-point/angle units depend on the consuming setter.
struct CombatCoordinate3 { signed int x, y, z; };
extern "C" {
extern const CombatCoordinate3 BattleCamera_ConfigureRandomPairOrbit_FormationTransformTemplate = {0, 4096, 0};
}
