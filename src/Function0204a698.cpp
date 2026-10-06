#include <globaldefs.h>

extern "C" ARM void func_0204a698(unsigned int controlBits)
{
    volatile unsigned short* const displayControl =
        reinterpret_cast<volatile unsigned short*>(0x0400000C);
    *displayControl = (*displayControl & ~3u) | controlBits;
}
