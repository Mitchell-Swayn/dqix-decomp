#include <std_library_functions.h>

extern "C" void* func_02079fc8(void* object)
{
    char* bytes = (char*)object;
    memset(bytes, 0, 0x0c);
    memset(bytes + 0x0c, 0, 0x0c);
    memset(bytes + 0x18, 0, 0x0c);
    memset(bytes + 0x24, 0, 0x0c);
    return object;
}
