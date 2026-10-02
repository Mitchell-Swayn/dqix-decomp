#pragma once

// The selector routine addresses eight allocated C-string pointers through the entry pointer.
struct WorldScriptArrayValues
{
    char* values[8];
};

struct WorldScriptArrayEntry
{
    short key;
    unsigned short unknown2;
    char* unknown4;
    char* unknown8;
    WorldScriptArrayValues* values;
    char* unknown10;
    char* unknown14;
};

struct WorldScriptArrayList
{
    WorldScriptArrayEntry* entries;
    short count;
    short capacity;
    const short* keyFilter;
    short capacityOverride;
    unsigned short stringMask;
};

typedef char WorldScriptArrayValuesSizeCheck[
    sizeof(WorldScriptArrayValues) == 32 ? 1 : -1];
typedef char WorldScriptArrayEntrySizeCheck[
    sizeof(WorldScriptArrayEntry) == 24 ? 1 : -1];
typedef char WorldScriptArrayListSizeCheck[
    sizeof(WorldScriptArrayList) == 16 ? 1 : -1];

class SafeAllocator;
struct WorldScriptArrayLoadingState
{
    SafeAllocator* allocator;
    WorldScriptArrayList* list;
};

typedef char WorldScriptArrayLoadingStateSizeCheck[
    sizeof(WorldScriptArrayLoadingState) == 8 ? 1 : -1];

extern "C" {
    extern WorldScriptArrayLoadingState data_02108fc0;
    void func_0208d51c(WorldScriptArrayEntry*);
    void func_0208d928(WorldScriptArrayList*, const WorldScriptArrayEntry*);
    void func_0208d8ec(WorldScriptArrayList*, SafeAllocator*, int capacity);
    WorldScriptArrayEntry* func_0208d994(WorldScriptArrayList*, int key);
}
