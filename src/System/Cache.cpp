#include "System/Cache.h"

#define CACHE_LINE_LENGTH 32
#define CACHE_LINE_LENGTH_BITMASK 0x1f

#define DATA_CACHE_SIZE 4096
#define INSTRUCTION_CACHE_SIZE 8192

#define CACHE_NUM_WAYS 4

// https://developer.arm.com/documentation/ddi0201/d/programmer-s-model/cp15-register-map-summary/register-7--cache-operations-register
// Note the manual uses the term 'flush' to mean 'invalidate' (no cleaning).

#pragma optimization_level 1
// Original: arm9/main @ 0x020C824C; symbol: _Z19InvalidateDataCachev; size: 0xC.
void InvalidateDataCache()
{
    int zero = 0;
    __asm("mcr p15, 0x0, zero, c7, c6, 0");
}
#pragma optimization_level 2

// Original: arm9/main @ 0x020C8258; symbol: _Z14CleanDataCachev; size: 0x2C.
void CleanDataCache()
{
    int setId;
    int wayId;
    __asm("mov wayId, #0");
    do
    {
        __asm("mov setId, #0");
        do 
        {
            int mask = wayId | setId;
            __asm("mcr p15, 0, mask, c7, c10, 2");
            setId += CACHE_LINE_LENGTH;
        } while (setId < DATA_CACHE_SIZE / CACHE_NUM_WAYS);
        __asm("add wayId, wayId, 1 << 30");
    } while (wayId != 0);
}

// Original: arm9/main @ 0x020C8284; symbol: _Z24CleanInvalidateDataCachev; size: 0x34.
void CleanInvalidateDataCache()
{
    int setId;
    int wayId;
    __asm("mov r12, #0");
    __asm("mov wayId, #0");
    do
    {
        __asm("mov setId, #0");
        do
        {
            int mask = wayId | setId;
            __asm("mcr p15, 0, r12, c7, c10, 4");
            __asm("mcr p15, 0, mask, c7, c14, 2");

            setId += CACHE_LINE_LENGTH;
        } while (setId < DATA_CACHE_SIZE / CACHE_NUM_WAYS);
        
        __asm("add wayId, wayId, 1 << 30");
    } while (wayId != 0);
}

// Original: arm9/main @ 0x020C82B8; symbol: _Z24InvalidateDataCacheRangePKvj; size: 0x1C.
void InvalidateDataCacheRange(const void* where, unsigned int len)
{
    int end = len + (int)where;
    unsigned char* dst = (unsigned char*)((unsigned int)where & ~CACHE_LINE_LENGTH_BITMASK);

    do 
    {
        __asm("mcr p15, 0x0, dst, c7, c6, 1");
        dst += CACHE_LINE_LENGTH;
    } while ((int)dst < end);
}

// Original: arm9/main @ 0x020C82D4; symbol: _Z15CleanCacheRangePKvj; size: 0x1C.
void CleanCacheRange(const void* where, unsigned int len)
{
    int end = len + (int)where;
    unsigned char* dst = (unsigned char*)((unsigned int)where & ~CACHE_LINE_LENGTH_BITMASK);

    do 
    {
        __asm("mcr p15, 0x0, dst, c7, c10, 1");
        dst += CACHE_LINE_LENGTH;
    } while ((int)dst < end);
}

// Original: arm9/main @ 0x020C82F0; symbol: _Z25CleanInvalidateCacheRangePKvj; size: 0x24.
void CleanInvalidateCacheRange(const void* where, unsigned int len)
{
    __asm("mov r12, 0"); // Need a blank register for use with drain write buffer
    int end = len + (int)where;
    unsigned char* dst = (unsigned char*)((unsigned int)where & ~CACHE_LINE_LENGTH_BITMASK);

    do
    {
        // "Drain write buffer"
        __asm("mcr p15, 0x0, r12, c7, c10, 4");
        __asm("mcr p15, 0x0, dst, c7, c14, 1");
        dst += CACHE_LINE_LENGTH;
    } while ((int)dst < end);
}

#pragma optimization_level 1
// Original: arm9/main @ 0x020C8314; symbol: _Z16DrainWriteBufferv; size: 0xC.
void DrainWriteBuffer()
{
    int zero = 0;
    __asm("mcr p15, 0x0, zero, c7, c10, 4");
}
#pragma optimization_level 2

#pragma optimization_level 1
// Original: arm9/main @ 0x020C8320; symbol: _Z26InvalidateInstructionCachev; size: 0xC.
void InvalidateInstructionCache()
{
    int zero = 0;
    __asm("mcr p15, 0x0, zero, c7, c5, 0");
}
#pragma optimization_level 2

// Original: arm9/main @ 0x020C832C; symbol: _Z31InvalidateInstructionCacheRangePKvj; size: 0x1C.
void InvalidateInstructionCacheRange(const void* where, unsigned int len)
{
    int end = len + (int)where;
    unsigned char* dst = (unsigned char*)((unsigned int)where & ~CACHE_LINE_LENGTH_BITMASK);
    do
    { 
        __asm("mcr p15, 0x0, dst, c7, c5, 1");
        dst += CACHE_LINE_LENGTH;
    } while ((int)dst < end);
}