#include <globaldefs.h>
ARM
struct State { unsigned first; unsigned bit:1; unsigned rest:31; };
// Original: arm9/ov027 @ 0x021DD3E0; symbol: MBi_IsTaskBusy; size: 0x18.
// Returns whether bit zero of the object's second word is set.
extern "C" bool MBi_IsTaskBusy(const State* self) { return self->bit != 0; }
