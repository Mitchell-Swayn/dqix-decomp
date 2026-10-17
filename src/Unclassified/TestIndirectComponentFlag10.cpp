#include <globaldefs.h>

// Original: arm9/main @ 0x0204936C; symbol: func_0204936c; size: 0x24.
extern "C" bool TestIndirectComponentFlag10(void* object)
{
    void* component = *(void**)((unsigned char*)object + 0x13c);
    if (component == 0) {
        return false;
    }
    return (*(unsigned int*)((unsigned char*)component + 0x20) & 0x10) != 0;
}
