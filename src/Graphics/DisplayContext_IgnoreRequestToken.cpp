#include <globaldefs.h>
// Original: arm9/main @ 0x02094B38; symbol: func_02094b38; size: 0x4.
// Callers pass an object in r0 and a request token in r1; both are ignored.
// Token meaning and the owning object's subsystem remain unresolved.
extern "C" ARM void DisplayContext_IgnoreRequestToken(void* object, unsigned int requestToken)
{
}
