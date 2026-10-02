#pragma once

typedef void (*RuntimeExitHandler)();
typedef void (*RuntimeSignalHandler)(int);

struct RuntimeExitState {
    RuntimeExitHandler lateHandler;
    RuntimeExitHandler earlyHandler;
    volatile int handlerCount;
    int aborting;
};

struct RuntimeDestructorNode {
    RuntimeDestructorNode* next;
    void (*destroy)(void*, int);
    void* object;
};

extern RuntimeExitState data_020f2e60;
extern RuntimeExitHandler volatile data_020f2e70[64];
extern unsigned int data_020f2f70[9];
extern unsigned int data_020f2f94[9];
extern RuntimeSignalHandler data_020f3394[7];
extern RuntimeDestructorNode* data_020f33b0;
