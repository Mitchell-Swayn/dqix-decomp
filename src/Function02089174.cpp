#include <globaldefs.h>

extern "C" void func_02089174(void* state)
{
    unsigned char* bytes = static_cast<unsigned char*>(state);
    bytes[0x7c] = 3;
    bytes[0x9f] = 0;

    unsigned int flags = *reinterpret_cast<unsigned int*>(bytes + 0x18);
    *reinterpret_cast<unsigned int*>(bytes + 0x18) = flags | 0x800;
}
