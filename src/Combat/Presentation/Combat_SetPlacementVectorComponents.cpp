#include <globaldefs.h>
#include <Graphics/Vector.h>
ARM
#pragma force_active on
// Original: arm9/ov025 @ 0x021E4448; symbol: func_ov025_021e4448; size: 0x8.
extern "C" void Combat_SetPlacementVectorComponents(Vector3fix* output, int x, int y, int z)
{
    output->x = x;
    output->y = y;
    output->z = z;
}
#pragma force_active reset
