#include "Filesystem/FileAccessor.h"

// MODSN decoder input backed by an already-open NitroVM. The logical cursor
// differs from the VM cursor during a sector-aligned asynchronous read.
struct DecoderFileStream;
struct DecoderStreamMethods
{
    void (*destroy)(DecoderFileStream*);
    DecoderFileStream* (*deleteStream)(DecoderFileStream*);
    CBool (*seek)(DecoderFileStream*, unsigned);
    CBool (*read)(DecoderFileStream*, void*, unsigned);
    unsigned (*readAligned)(DecoderFileStream*, void*, unsigned);
    void (*awaitRead)(DecoderFileStream*);
    void (*finish)(DecoderFileStream*);
    unsigned reserved;
};
typedef char DecoderStreamMethodsSizeCheck[sizeof(DecoderStreamMethods) == 0x20 ? 1 : -1];

struct DecoderFileStream
{
    const DecoderStreamMethods* methods;
    unsigned length;
    unsigned position;
    NitroVM* file;
    unsigned char readPending;
};
typedef char DecoderFileStreamSizeCheck[sizeof(DecoderFileStream) == 0x14 ? 1 : -1];

extern "C" {
DecoderFileStream* func_ov016_0218e62c(DecoderFileStream*);

CBool func_ov016_0218f508(DecoderFileStream* stream, NitroVM* file)
{
    stream->file = file;
    stream->length = file->fileInfo.endOffset - file->fileInfo.startOffset;
    stream->position = stream->file->fileInfo.cursorPos - stream->file->fileInfo.startOffset;
    stream->readPending = 0;
    return 1;
}

CBool func_ov016_0218f540(DecoderFileStream* stream, unsigned position)
{
    if (stream->readPending == 1) {
        NitroVM_AwaitCommandCompletion(stream->file);
        stream->readPending = 0;
    }
    if (!NitroVM_Seek(stream->file, position, 0))
        return 0;
    stream->position = position;
    return 1;
}

#pragma push
// This method uses the speed-oriented early-return sequence rather than
// predicating the entire cursor update (the other methods match defaults).
#pragma optimize_for_size off
CBool func_ov016_0218f58c(DecoderFileStream* stream, void* destination, unsigned bytes)
{
    if (stream->readPending == 1) {
        NitroVM_AwaitCommandCompletion(stream->file);
        NitroVM_Seek(stream->file, stream->position, 0);
        stream->readPending = 0;
    }
    if (NitroVM_ReadSync(stream->file, destination, bytes) == -1)
        return 0;
    stream->position += bytes;
    return 1;
}
#pragma pop

unsigned func_ov016_0218f5fc(DecoderFileStream* stream, void* destination, unsigned bytes)
{
    unsigned alignedPosition = stream->position & ~0x1ffu;
    unsigned prefix = stream->position - alignedPosition;
    unsigned alignedBytes = bytes + prefix;
    if (alignedBytes & 0x1ff)
        alignedBytes = (alignedBytes & ~0x1ffu) + 0x200;
    NitroVM_Seek(stream->file, alignedPosition, 0);
    if (NitroVM_ReadAsync(stream->file, destination, alignedBytes) == -1)
        return 0;
    stream->position += bytes;
    stream->readPending = 1;
    return prefix;
}

void func_ov016_0218f678(DecoderFileStream* stream)
{
    if (stream->readPending == 1)
        NitroVM_AwaitCommandCompletion(stream->file);
    stream->readPending = 0;
}

void func_ov016_0218f6a0(DecoderFileStream* stream)
{
    stream->methods->awaitRead(stream);
}

void func_ov016_0218f6b4(DecoderFileStream*) {}

DecoderStreamMethods data_ov016_0219d0a0 = {
    func_ov016_0218f6b4, func_ov016_0218e62c,
    func_ov016_0218f540, func_ov016_0218f58c, func_ov016_0218f5fc,
    func_ov016_0218f678, func_ov016_0218f6a0, 0
};
}
