#include <globaldefs.h>
// Original: arm9/ov024 @ 0x021DD260; symbol: func_ov024_021dd260; size: 0x18.
// Field roles are unresolved; offsets describe the observed layout.
extern "C" ARM int Combat_HasSuperHighTension(void* object)
{
    unsigned char* record = *(unsigned char**)((unsigned char*)object + 0x138);
    return (*(unsigned int*)(record + 0x14) & 0x01000000) != 0;
}
