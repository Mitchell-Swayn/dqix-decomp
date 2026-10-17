#include <globaldefs.h>
ARM
struct State;
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
// Original: arm9/ov004 @ 0x02156F04; symbol: func_ov004_02156f04; size: 0x34.
extern "C" void* World_FindType8EntryByStateValue(State* state, unsigned value) {
    void* head = func_ov011_021849c8(state);
    void* entry = func_ov023_021f6880(head, value);
    if (!entry) goto fail;
    if (OV023_ReadHalfwordField04(entry) == 8) return entry;
fail:
    return 0;
}
