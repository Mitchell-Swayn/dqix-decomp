#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021A7C8C; symbol: Unclassified_GetPointerAtOffset0C; size: 0x8.
// Returns the input record pointer advanced by 0x0C; its caller reads a halfword at returned offset +4.
extern "C" void *Field_GetDeferredActorRequestDescriptor(void *self) { return (unsigned char *)self + 0x0c; }
