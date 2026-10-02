#pragma once
struct RuntimeExceptionRecord {
    void* object;
    const unsigned char* type;
    void (*destroy)(void*, int);
    void* adjusted;
    void* indirect;
};
struct RuntimeExceptionState {
    const unsigned char* type;
    void* object;
    void (*destroy)(void*, int);
    unsigned int reserved0c[3];
    char* frame;
};

typedef char RuntimeExceptionRecordSizeCheck[sizeof(RuntimeExceptionRecord) == 20 ? 1 : -1];
typedef char RuntimeExceptionStatePrefixSizeCheck[sizeof(RuntimeExceptionState) == 28 ? 1 : -1];
