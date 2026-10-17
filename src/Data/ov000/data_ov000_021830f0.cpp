#include <globaldefs.h>
// Combat formation position/rotation vector template. Copied as a three-word coordinate value; exact fixed-point/angle units depend on the consuming setter.
struct CombatCoordinate3 { signed int x, y, z; };
extern "C" {
extern const CombatCoordinate3 data_ov000_021830f0 = {0, 204, 0};
}
