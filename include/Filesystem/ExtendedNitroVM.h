#pragma once

#include "NitroVM.h"

class Decompressor;

// Any compressed section 
struct CompressionPrefix
{
    unsigned int compressionType : 3;
    unsigned int decompressedLength : 29;

    unsigned int GetDecompressedLength() const;
};

// sizeof == 76 == 0x4c
class ExtendedNitroVM
{
public:
    enum Status {
        Status_NotOpen = 0,
        Status_Open = 1,
        Status_2_Unknown = 2
    };

    unsigned short status;
    unsigned short isBadState;
    NitroVM machine;

    void ZeroInitialize();

    // Probably more like IsOpen, but requires to be open and have the 
    // underlying object be in a valid state. If status == 2 then always
    // returns true, not sure what that's about 
    bool IsInReadableState();
    unsigned int GetFileSize();
    bool Seek(unsigned int where);
    // Completes the pending operation then resets the VM to a blank state.
    // Returns true if successful
    bool Close();

    // Not sure what the idea behind the bool is, but it's always false.
    // If set to true, most of the function gets skipped. If a file is already
    // open, it will be closed and the new file opened
    bool Open(const char* filePath, bool skip);
    // Returns number of bytes copied
    unsigned int Read(void* into, unsigned int capacity);

    // Cancels any pending operation and leaves the VM in an invalid state.
    // Returns true if a file was open
    bool Abort();

    // Decompresses the current file using the Decompressor provided.
    // The numBytesToRead and readPosTracker variables will be decreased
    // and increased by the appropriate amount, but readPosTracker is never
    // actually used. (If all goes well, numBytesToRead should end up at zero).
    // The function also returns the final value of readPosTracker.
    // To perform the decompression, the file must first be loaded into memory
    // into 'scratch space', provided with the final two arguments.
    // 
    //
    // In practice when this is used, the scratch space is the same space where
    // the decompressed file will be saved. The (compressed) file is loaded into
    // the end of the space (e.g. if the space is 100 bytes and the compressed
    // file is 80 bytes, it will be loaded at offset 20). Then as the 
    // decompression procedure runs, the start of the space fills up with the
    // decompressed file and gradually overwrites the compressed version, but
    // bytes are only overwritten after they have been used for everything necessary.
    unsigned int DecompressWithScratchSpace(Decompressor& decompressor, unsigned int& outDecompressedLength,
        unsigned int& numBytesToRead, unsigned int& readPosTracker,
        void* scratchSpace, unsigned int scratchSpaceCapacity);

    // Decompresses bytes from the current file, at the current position,
    // into the specified space. It is assumed that the bytes at the current
    // position are the beginning of compressed data (and in particular, the
    // first four encode the compression type).
    //
    // Returns the number of bytes read, or zero if the procedure failed.
    // (Insufficient space in the output buffer will cause a failure, not a 
    // buffer overrun).
    unsigned int DecompressBytes(void* output, unsigned int& outDecompressedSize,
        unsigned int numBytesToRead, unsigned int outputCapacity);
};

// sizeof == 552 == 0x228
class Decompressor
{
public:
    unsigned char* writeOutputPtr;
    unsigned int remainingOutputBytes;
    // The three native algorithms reuse bytes +0x08..+0x1b differently.
    // These views describe observed accesses, not recovered original typedefs.
    union AlgorithmState
    {
        struct LZState
        {
            unsigned int token;                 // +0x08: pending length/offset bits
            unsigned char unused_0C[3];
            unsigned char flags;                // +0x0f: next flag in bit7
            unsigned char remainingFlagBits;    // +0x10
            unsigned char tokenReadState;       // +0x11: initialized to3
            unsigned char extendedLengthMode;   // +0x12: zero in this wrapper
            unsigned char unused_13[9];
        } lz;
        struct HuffmanState
        {
            unsigned char* treeCursor;           // +0x08: copy cursor, then node
            unsigned int inputBits;              // +0x0c
            unsigned int outputBits;             // +0x10
            short remainingTreeBytes;            // +0x14: -1 before size byte
            unsigned char inputBitCount;         // +0x16
            unsigned char outputBitCount;        // +0x17
            unsigned char symbolWidth;           // +0x18: four or eight bits
            unsigned char unused_19[3];
        } huffman;
        struct RLEState
        {
            unsigned char unused_08[3];
            unsigned char control;               // +0x0b: bit7 selects repeat
            unsigned short remainingRunBytes;    // +0x0c
            unsigned char unused_0E[14];
        } rle;
    } state;

    unsigned char huffmanTree[0x200]; // +0x1c; includes the tree-size byte

    unsigned int declaredOutputSize;
    unsigned int compressionType;
    void* alignedOutputEnd;

public:
    bool InitAndDecompress(void* out, unsigned int outCapacity, const void* in, unsigned int inLength);
    bool ProcessBytes(const void* input, unsigned int inputLength);
};

typedef char DecompressorLayoutCheck[sizeof(Decompressor) == 0x228 ? 1 : -1];

