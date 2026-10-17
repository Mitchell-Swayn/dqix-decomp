#include <globaldefs.h>
// Sentinel followed by four floating-point ratio inputs. Static initializer0218381c reads float fields at offsets4..16.
struct CombatRatioInputs { signed int sentinel; float ratios[4]; };
extern "C" {
CombatRatioInputs data_ov000_02183b0c = {-1, {30.0f, 180.0f, 30.0f, 180.0f}};
}
