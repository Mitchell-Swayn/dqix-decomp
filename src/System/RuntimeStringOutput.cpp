#pragma optimize_for_size off

struct RuntimeStringOutputState {
    char* buffer;
    unsigned int capacity;
    unsigned int written;
};

extern "C" void* memcpy(void*, const void*, unsigned int);
// Original: arm9/main @ 0x02003C3C; symbol: func_02003c3c; size: 0x44.
extern "C" int Runtime_AppendBoundedStringOutput(RuntimeStringOutputState* state, const char* text, unsigned int count)
{
    if (state->written + count > state->capacity)
        count = state->capacity - state->written;
    memcpy(state->buffer + state->written, text, count);
    state->written += count;
    return 1;
}

typedef int (*RuntimeStringWriter)(RuntimeStringOutputState*, const char*, unsigned int);
extern "C" int Runtime_WriteFormattedArgumentsToCallback(RuntimeStringWriter, RuntimeStringOutputState*, const char*, void*);
// Original: arm9/main @ 0x02003C80; symbol: func_02003c80; size: 0x68.
extern "C" int Runtime_FormatIntoBoundedString(char* buffer, unsigned int size, const char* format, void* args)
{
    RuntimeStringOutputState state;
    state.buffer = buffer;
    state.capacity = size;
    state.written = 0;
    int result = Runtime_WriteFormattedArgumentsToCallback(Runtime_AppendBoundedStringOutput, &state, format, args);
    if (buffer) {
        if ((unsigned int)result < size)
            buffer[result] = 0;
        else if (size)
            (buffer + size)[-1] = 0;
    }
    return result;
}
