#pragma once

// Runtime stream ABI reconstructed from buffer and flush operations.
// Reserved fields retain their observed offsets; the stream table remains external.
struct RuntimeStream {
    unsigned int handle;
    unsigned int modeLow : 2;
    unsigned int accessMode : 3;
    unsigned int modeReserved : 2;
    unsigned int kind : 3;
    unsigned int modeReserved2 : 2;
    unsigned int binary : 1;
    unsigned int modeHigh : 19;
    unsigned int ioState : 3;
    unsigned int stateHigh : 29;
    unsigned char reserved0c;
    unsigned char error;
    unsigned char reserved0e[10];
    unsigned int position;
    char* buffer;
    unsigned int bufferSize;
    char* cursor;
    unsigned int remaining;
    unsigned int alignmentMask;
    unsigned int reserved30;
    unsigned int bufferPosition;
    unsigned int reserved38[2];
    int (*write)(unsigned int, char*, unsigned int*, void*);
    unsigned int reserved44;
    void* context;
};
// Original data: arm9/main @ 0x20eebe0; symbol: data_020eebe0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0000000024010000000000000000000000000000000000000000000090320f020001000090320f020000000000000000000000000000000000000000ccd80002 ...; full span in module reference.
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeStream RuntimeFlushAllOpenStreams_UnknownRoleProcedureReferenceRecords[3];
extern "C" int Runtime_FlushAllOpenStreams();
extern "C" void RuntimeStreamBuffers_IgnoreBufferRelease(char*, unsigned int*);
extern "C" void Runtime_ResetAlignedStreamBuffer(RuntimeStream*);
extern "C" int Runtime_FlushBufferedStreamOutput(RuntimeStream*, unsigned int*);
extern "C" int RuntimeStreamBuffers_FlushStreamOrAllStreams(RuntimeStream*);

typedef char RuntimeStreamSizeCheck[sizeof(RuntimeStream) == 0x4c ? 1 : -1];

