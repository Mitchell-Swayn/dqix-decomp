#pragma once
#include "BackgroundLoaderContract.h"
#include "System/RuntimeState.h"

// Reconstructed resident representation. Original ov034 source type names are unknown.
// This POD has the BackgroundLoader field layout without native C++ startup code.
struct Ov34LoaderStorage {
    const void* dispatch;
    ProcessorContext context;
    ExtendedNitroVM reader;
    void* scratchSpace;
    volatile unsigned int scratchSize;
    volatile int rightmostByte;
    volatile unsigned int rightArenaUsage;
    int maximumUsage;
    volatile int pendingTasks;
    BackgroundLoader::Task tasks[24];
    volatile unsigned int processLocks;
    volatile int flags;
    int unknown790;
};
struct Ov34LoaderDispatch {
    unsigned int reserved[2];
    int (*process)(BackgroundLoader*);
};
extern "C" int func_ov034_022a21a8(BackgroundLoader*);
extern "C" BackgroundLoader* func_ov034_022a29b8(BackgroundLoader*);
extern "C" BackgroundLoader* func_ov034_022a29e4(BackgroundLoader*, int flags);

struct Ov34LoaderAccess : BackgroundLoader {using BackgroundLoader::AllocateInScratchSpace;using BackgroundLoader::FreeScratchSpace;using BackgroundLoader::RefreshCounters;};
