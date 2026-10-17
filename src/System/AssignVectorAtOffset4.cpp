#include <globaldefs.h>
ARM
#include "System/Matrix.h"
// Original: arm9/main @ 0x0202EF04; symbol: func_0202ef04; size: 0x10.
extern "C" Vector3i& AssignVectorAtOffset4(unsigned char* object, const Vector3i& source) { return *reinterpret_cast<Vector3i*>(object+4)=source; }
