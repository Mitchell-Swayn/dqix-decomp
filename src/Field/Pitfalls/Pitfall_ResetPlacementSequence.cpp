#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
struct Overlay10State {
    unsigned char phase;
    unsigned char flag;
    unsigned short value;
    int handle;
    unsigned int auxiliary;
    unsigned char records[8];
    SafeAllocator resource;
};
extern "C" void MessageTextTable_Reset(void*);
// Original: arm9/ov010 @ 0x021842A0; symbol: func_ov010_021842a0; size: 0x38.
extern "C" void Pitfall_ResetPlacementSequence(Overlay10State* state) {
    state->phase = 0;
    state->value = 0;
    state->handle = -1;
    MessageTextTable_Reset(state->records);
    state->resource.ResetAllocatorPointer();
    state->flag = 0;
}
