#include <globaldefs.h>
#pragma optimization_level 2
#include <System/Mutex.h>
#include <Resource/ResourceMutex.h>

extern "C" volatile unsigned data_01ffd348;
extern "C" volatile unsigned char data_01ffd344, data_01ffd340;
extern "C" Mutex data_01ffd34c;
extern "C" unsigned char data_01ffd364[];
extern "C" char data_01ffd394[];
struct Entry { unsigned offset, unknown; };
extern "C" Entry data_020e8f20[];
extern "C" void ProcessorContext_SleepOrYieldPriorityPeers(int);
extern "C" void ProcessOverlayAndReturnSuccess(void*);

// Original: arm9/main @ 0x020A1CCC; symbol: func_020a1ccc; size: 0x118.
extern "C" ARM int OverlayLoader_LoadIndexedOverlayWithSharedStatusLocks(unsigned index)
{
    int result = 0;
    if (index < 35) {
        volatile Entry* table = data_020e8f20;
        unsigned slot = data_01ffd348;
        if (data_01ffd344) LockMutex(&data_01ffd34c);
        // Shared status bytes must be stored before the following flag read.
        volatile signed char* buffer = (signed char*)data_01ffd364 + slot * 6;
        buffer[table[index].offset] = index | 64;
        if (data_01ffd344) UnlockMutex(&data_01ffd34c);
        while (data_01ffd340) ProcessorContext_SleepOrYieldPriorityPeers(0);
        data_01ffd340 = 1;
        LockResourceMutex();
        ProcessOverlayAndReturnSuccess(data_01ffd394 + index * 44);
        UnlockResourceMutex();
        data_01ffd340 = 0;
        if (data_01ffd344) LockMutex(&data_01ffd34c);
        buffer[table[index].offset] = -1;
        if (data_01ffd344) UnlockMutex(&data_01ffd34c);
        result = 1;
    }
    return result;
}
