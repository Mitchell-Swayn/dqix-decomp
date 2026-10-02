#include "System/RuntimeStream.h"

#pragma optimize_for_size off
#pragma dont_inline on

// The original text-conversion hook consists only of a return instruction.
extern "C" void func_020017bc(char*, unsigned int*)
{
}

extern "C" void func_020017c0(RuntimeStream* stream)
{
    stream->cursor = stream->buffer;
    stream->remaining = stream->bufferSize;
    stream->remaining -= stream->position & stream->alignmentMask;
    stream->bufferPosition = stream->position;
}

extern "C" int func_020017f0(RuntimeStream* stream, unsigned int* written)
{
    unsigned int length = stream->cursor - stream->buffer;
    if (length) {
        stream->remaining = length;
        if (!stream->binary)
            func_020017bc(stream->buffer, &stream->remaining);
        int result = stream->write(stream->handle, stream->buffer, &stream->remaining, stream->context);
        if (written)
            *written = stream->remaining;
        if (result)
            return result;
        stream->position += stream->remaining;
    }
    func_020017c0(stream);
    return 0;
}

extern "C" int func_02001878(RuntimeStream* stream)
{
    if (!stream)
        return func_0200173c();
    if (stream->error || !stream->kind)
        return -1;
    if (stream->accessMode == 1)
        return 0;
    if (stream->ioState >= 3)
        stream->ioState = 2;
    if (stream->ioState == 2)
        stream->remaining = 0;
    if (stream->ioState != 1) {
        stream->ioState = 0;
        return 0;
    }
    if (func_020017f0(stream, 0)) {
        stream->error = 1;
        stream->remaining = 0;
        return -1;
    }
    stream->ioState = 0;
    stream->position = 0;
    stream->remaining = 0;
    return 0;
}
