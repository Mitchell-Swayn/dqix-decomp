#pragma once
// Descriptor ranges and action bytes used by the runtime unwinder.
struct RuntimeUnwindRange {
    unsigned int address;
    unsigned int sizeAndInline;
    const unsigned char* descriptor;
};
struct RuntimeUnwindTable {
    unsigned int address;
    const unsigned char* descriptor;
    const unsigned char* action;
    const RuntimeUnwindRange* begin;
    const RuntimeUnwindRange* end;
};
extern "C" const unsigned char* func_0200d9e4(const unsigned char*, unsigned int*);
extern "C" const unsigned char* func_0200f2bc(const unsigned char*);
extern "C" int func_0200f29c(RuntimeUnwindTable*, unsigned int);

typedef char RuntimeUnwindRangeSizeCheck[sizeof(RuntimeUnwindRange) == 12 ? 1 : -1];
typedef char RuntimeUnwindTableSizeCheck[sizeof(RuntimeUnwindTable) == 20 ? 1 : -1];
