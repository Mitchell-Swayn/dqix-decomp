#pragma once

// Five alternatives are stored as offsets before the resource is fixed up,
// then as pointers (and temporarily replaced by encoded stack strings by the
// interpreter). Parallel arrays describe the length and comparison mode.
union PatternStringReference {
    int offset;
    char* text;
};

struct PatternRecord {
    PatternStringReference alternatives[5];
    signed char lengths[5];
    unsigned char modes[5];
    unsigned char count;
    unsigned char unknown_1f;
};

// The interpreter at 02184d80 owns this state. The first 24 bytes remain
// unrecovered; the resource header and its two resolved arrays occupy 0x18..0x23.
struct PatternResource {
    unsigned int flags;
    PatternRecord* records;
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
