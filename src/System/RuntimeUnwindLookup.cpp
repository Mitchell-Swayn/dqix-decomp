#include "System/RuntimeUnwindTable.h"
#pragma optimize_for_size off
// Original: arm9/main @ 0x0200DA70; symbol: func_0200da70; size: 0x64.
extern "C" const RuntimeUnwindRange* Runtime_FindUnwindRangeForAddress(const RuntimeUnwindRange* table, int count, unsigned int address)
{
    int first = 0;
    int last = count - 1;
    if (first <= last) do {
        int middle = (first + last) >> 1;
        const RuntimeUnwindRange* range = table + middle;
        if (address < range->address) last = middle - 1;
        else if (address > range->address + (range->sizeAndInline & ~1)) first = middle + 1;
        else return range;
    } while (first <= last);
    return 0;
}
// Original: arm9/main @ 0x0200DAD4; symbol: func_0200dad4; size: 0x108.
extern "C" void Runtime_FindUnwindDescriptorForAddress(unsigned int address, RuntimeUnwindTable* state)
{
    state->descriptor = 0;
    state->action = 0;
    if (!RuntimeUnwind_InitializeEmptyRange(state, address))
        return;
    const RuntimeUnwindRange* range = Runtime_FindUnwindRangeForAddress(state->begin, state->end - state->begin, address);
    if (!range)
        return;
    state->descriptor = range->sizeAndInline & 1 ? (const unsigned char*)&range->descriptor : range->descriptor;
    state->address = range->address;
    unsigned int relative = address - range->address;
    const unsigned char* cursor = RuntimeUnwindHeader_SkipEncodedHeader(state->descriptor);
    unsigned int total = 0;
    unsigned int delta, length, offset;
    for (;;) {
        cursor = RuntimeUnwind_ReadCompactUnsignedInteger(cursor, &delta);
        if (delta == 0)
            return;
        cursor = RuntimeUnwind_ReadCompactUnsignedInteger(cursor, &length);
        cursor = RuntimeUnwind_ReadCompactUnsignedInteger(cursor, &offset);
        unsigned int start = total + delta;
        if (relative < start)
            return;
        total = start + length;
        if (relative <= total)
            break;
    }
    state->action = state->descriptor + offset;
}
// Original: arm9/main @ 0x0200DBDC; symbol: func_0200dbdc; size: 0x1C.
extern "C" unsigned char RuntimeUnwindTable_ReadActionOpcode(const RuntimeUnwindTable* state)
{
    return state->action ? *state->action & 0x1f : 0;
}
