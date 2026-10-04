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
extern RuntimeStream data_020eebe0[3];
extern "C" int func_0200173c();
extern "C" void func_020017bc(char*, unsigned int*);
extern "C" void func_020017c0(RuntimeStream*);
extern "C" int func_020017f0(RuntimeStream*, unsigned int*);
extern "C" int func_02001878(RuntimeStream*);

typedef char RuntimeStreamSizeCheck[sizeof(RuntimeStream) == 0x4c ? 1 : -1];

