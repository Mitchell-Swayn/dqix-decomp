#include "System/Graphics.h"

extern "C" void func_020c3984(unsigned int displayModeBits)
{
    DISPCNTSUB = (DISPCNTSUB & ~7u) | displayModeBits;
}
