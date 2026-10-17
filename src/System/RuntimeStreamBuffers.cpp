#include "System/RuntimeStream.h"

#pragma optimize_for_size off
#pragma dont_inline on

// The original text-conversion hook consists only of a return instruction.
// Original: arm9/main @ 0x020017BC; symbol: func_020017bc; size: 0x4.
extern "C" void RuntimeStreamBuffers_IgnoreBufferRelease(char*, unsigned int*)
{
}

// Original: arm9/main @ 0x020017C0; symbol: func_020017c0; size: 0x30.
extern "C" void Runtime_ResetAlignedStreamBuffer(RuntimeStream* stream)
{
    stream->cursor = stream->buffer;
    stream->remaining = stream->bufferSize;
    stream->remaining -= stream->position & stream->alignmentMask;
    stream->bufferPosition = stream->position;
}

// Original: arm9/main @ 0x020017F0; symbol: func_020017f0; size: 0x88.
extern "C" int Runtime_FlushBufferedStreamOutput(RuntimeStream* stream, unsigned int* written)
{
    unsigned int length = stream->cursor - stream->buffer;
    if (length) {
        stream->remaining = length;
        if (!stream->binary)
            RuntimeStreamBuffers_IgnoreBufferRelease(stream->buffer, &stream->remaining);
        int result = stream->write(stream->handle, stream->buffer, &stream->remaining, stream->context);
        if (written)
            *written = stream->remaining;
        if (result)
            return result;
        stream->position += stream->remaining;
    }
    Runtime_ResetAlignedStreamBuffer(stream);
    return 0;
}

// Original: arm9/main @ 0x02001878; symbol: func_02001878; size: 0xE8.
extern "C" int RuntimeStreamBuffers_FlushStreamOrAllStreams(RuntimeStream* stream)
{
    if (!stream)
        return Runtime_FlushAllOpenStreams();
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
    if (Runtime_FlushBufferedStreamOutput(stream, 0)) {
        stream->error = 1;
        stream->remaining = 0;
        return -1;
    }
    stream->ioState = 0;
    stream->position = 0;
    stream->remaining = 0;
    return 0;
}
