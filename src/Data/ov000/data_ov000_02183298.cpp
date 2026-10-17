#include <globaldefs.h>
// Combat formation position/rotation vector template. Copied as a three-word coordinate value; exact fixed-point/angle units depend on the consuming setter.
struct CombatCoordinate3 { signed int x, y, z; };
extern "C" {
extern const CombatCoordinate3 data_ov000_02183298 = {4096, 7168, 9216};
}
