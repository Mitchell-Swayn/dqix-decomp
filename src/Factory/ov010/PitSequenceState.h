#pragma once

#include "Memory/SafeAllocator.h"

// func_020729b4 allocates eight-byte records; func_02072a68 searches their
// signed identifiers and returns the associated text pointer.
struct PitTextEntry {
    short identifier_;
    short unused_02_;
    const char* text_;
};

struct PitTextTable {
    PitTextEntry* entries_;
    short capacity_;
    short count_;
};

// Layout observed in the ov010 update routine. The filenames identify the
// str_pit resource; the precise gameplay meaning of "pit" remains unknown.
struct PitSequenceState {
    unsigned char phase_;
    unsigned char effectEnabled_;
    unsigned short delay_;
    // The cleanup routine reloads this after obtaining the loader singleton.
    volatile int loadTask_;
    int effectObjectIndex_;
    PitTextTable text_;
    SafeAllocator allocator_;
};

extern "C" void func_ov010_021842a0(PitSequenceState* state);
extern "C" void func_ov010_021842d8(PitSequenceState* state);
extern "C" int func_ov010_02184354(PitSequenceState* state);
