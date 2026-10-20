#include <globaldefs.h>
#include "World/Zone3DEmbeddedState.h"
#include "std_library_functions.h"

// Original: arm9/main @ 0x020DEEB8; symbol: func_020deeb8; size: 0x3C.
extern "C" int SerializedLoader_LoadAndInitializeFiveWordOutput(ZoneState2754::Data* loader, void* output, unsigned int value, void* file, unsigned int size)
{
    loader->LoadSerializedData(file, size);
    memset(output, 0, 0xc);
    *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(output) + 0xc) = value;
    *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(output) + 0x10) = 0;
    return 1;
}
