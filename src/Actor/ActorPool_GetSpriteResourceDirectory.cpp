#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0203D004; symbol: func_0203d004; size: 0x4.
// Returns the supplied object pointer unchanged. Callers reuse the returned r0
// as an object pointer; the object class and accessor role remain unestablished.
extern "C" void* ActorPool_GetSpriteResourceDirectory(void* object)
{
    return object;
}
