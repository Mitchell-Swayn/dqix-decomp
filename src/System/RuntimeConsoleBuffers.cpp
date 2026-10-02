// The three initial RuntimeStream descriptors each use a 256-byte buffer.
// Their handles 2, 1 and 0 reference these buffers in ascending address order.
// Keep the descriptor table external until all of its callback ABI is recovered.
struct RuntimeConsoleBuffers {
    char handle2[256];
    char handle1[256];
    char handle0[256];
};

RuntimeConsoleBuffers gRuntimeConsoleBuffers;
typedef char RuntimeConsoleBuffersSizeCheck[sizeof(RuntimeConsoleBuffers) == 768 ? 1 : -1];
