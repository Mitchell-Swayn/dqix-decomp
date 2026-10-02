#pragma once

// The interpreter at 02184d80 owns this state. The first 24 bytes remain
// unrecovered; the resource header and its two resolved arrays occupy 0x18..0x23.
struct PatternResource {
    unsigned int flags;
    void* records;
    char* strings;
};

struct PatternState {
    unsigned char unknown_00[0x18];
    PatternResource resource;
    char* selectedPattern;
    unsigned short selectedOffset;
    unsigned char delimiters[15];
};

extern "C" int func_020424e4(const char* text, int encoding);
extern "C" int func_02001aec(const void* left, const void* right, unsigned int count);
extern "C" void* memset(void* destination, int value, unsigned int count);
