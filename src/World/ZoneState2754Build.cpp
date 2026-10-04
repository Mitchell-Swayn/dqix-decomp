#include "World/Zone3DEmbeddedState.h"
#include "std_library_functions.h"

extern "C" bool func_020def98(SafeAllocator*, ZoneState2754::Data*, ZoneState2754::Data*, const short*, short);
extern "C" bool func_020df374(SafeAllocator*, ZoneState2754::Data*, ZoneState2754::Data*, const short*, short, int, int);

bool ZoneState2754::BuildForKey(SafeAllocator* allocator, void* file, unsigned int size, short key)
{
    return BuildForKeys(allocator, file, size, &key, 1);
}

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

bool ZoneState2754::BuildAlternateForKey(SafeAllocator* allocator, void* file, unsigned int size, short key)
{
    return BuildAlternateForKeys(allocator, file, size, &key, 1);
}

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
