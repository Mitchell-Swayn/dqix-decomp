#include "World/Zone3DEmbeddedState.h"
#include "std_library_functions.h"

extern "C" bool func_020def98(SafeAllocator*, ZoneState2754::Data*, ZoneState2754::Data*, const short*, short);
extern "C" bool func_020df374(SafeAllocator*, ZoneState2754::Data*, ZoneState2754::Data*, const short*, short, int, int);

// Original: arm9/main @ 0x020DE980; symbol: _ZN13ZoneState275411BuildForKeyEP13SafeAllocatorPvjs; size: 0x24.
bool ZoneState2754::BuildForKey(SafeAllocator* allocator, void* file, unsigned int size, short key)
{
    return BuildForKeys(allocator, file, size, &key, 1);
}

// Original: arm9/main @ 0x020DE9A4; symbol: _ZN13ZoneState275412BuildForKeysEP13SafeAllocatorPvjPKst; size: 0x9C.
bool ZoneState2754::BuildForKeys(SafeAllocator* allocator, void* file, unsigned int size, const short* keys, unsigned short count)
{
    memset(&data, 0, sizeof(data));
    if (!allocator || !file || !size || !keys || !count) return false;
    Data source;
    source.LoadSerializedData(file, size);
    bool result = func_020def98(allocator, &data, &source, keys, count);
    unknown_14 = result && data.primaryCount > 1;
    return result;
}

// Original: arm9/main @ 0x020DEA40; symbol: _ZN13ZoneState275420BuildAlternateForKeyEP13SafeAllocatorPvjs; size: 0x24.
bool ZoneState2754::BuildAlternateForKey(SafeAllocator* allocator, void* file, unsigned int size, short key)
{
    return BuildAlternateForKeys(allocator, file, size, &key, 1);
}

// Original: arm9/main @ 0x020DEA64; symbol: _ZN13ZoneState275421BuildAlternateForKeysEP13SafeAllocatorPvjPKss; size: 0xA4.
bool ZoneState2754::BuildAlternateForKeys(SafeAllocator* allocator, void* file, unsigned int size, const short* keys, short count)
{
    memset(&data, 0, sizeof(data));
    if (!allocator || !file || !size || !keys || !count) return false;
    Data source;
    source.LoadSerializedData(file, size);
    bool result = func_020df374(allocator, &data, &source, keys, count, 0, 0);
    unknown_14 = result && data.primaryCount > 1;
    return result;
}
