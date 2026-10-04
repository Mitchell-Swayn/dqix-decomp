#include "System/RuntimeUnwindTable.h"
#pragma optimize_for_size off
extern "C" const RuntimeUnwindRange* func_0200da70(const RuntimeUnwindRange* table, int count, unsigned int address)
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
extern "C" void func_0200dad4(unsigned int address, RuntimeUnwindTable* state)
{
    state->descriptor = 0;
    state->action = 0;
    if (!func_0200f29c(state, address))
        return;
    const RuntimeUnwindRange* range = func_0200da70(state->begin, state->end - state->begin, address);
    if (!range)
        return;
    state->descriptor = range->sizeAndInline & 1 ? (const unsigned char*)&range->descriptor : range->descriptor;
    state->address = range->address;
    unsigned int relative = address - range->address;
    const unsigned char* cursor = func_0200f2bc(state->descriptor);
    unsigned int total = 0;
    unsigned int delta, length, offset;
    for (;;) {
        cursor = func_0200d9e4(cursor, &delta);
        if (delta == 0)
            return;
        cursor = func_0200d9e4(cursor, &length);
        cursor = func_0200d9e4(cursor, &offset);
        unsigned int start = total + delta;
        if (relative < start)
            return;
        total = start + length;
        if (relative <= total)
            break;
    }
    state->action = state->descriptor + offset;
}
extern "C" unsigned char func_0200dbdc(const RuntimeUnwindTable* state)
{
    return state->action ? *state->action & 0x1f : 0;
}
