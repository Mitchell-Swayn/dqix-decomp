// Original: arm9/main @ 0x02097280; symbol: func_02097280; size: 0x30.
#include <globaldefs.h>
struct OptionalOffsetBase { unsigned unknown[2]; char *base; };
// ARM9 main, original func_02097280 at 0x02097280.
// Proposed semantic name: ResolveOptionalRelativePointer.
extern "C" ARM char *ResolveOptionalRelativePointer(const OptionalOffsetBase *state, const char *encodedPointer, char *fallback)
{
    // Legacy MWCC null-origin pointer difference preserves serialized pointer offsets.
    bool invalid = true;
    int relative = encodedPointer - (const char *)0;
    if (relative != -1 && state->base) invalid = false;
    if (!invalid) fallback = state->base + relative;
    return fallback;
}
