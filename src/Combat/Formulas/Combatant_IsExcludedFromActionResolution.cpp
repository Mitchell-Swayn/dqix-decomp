#include <globaldefs.h>
// Original: arm9/ov024 @ 0x021E6798; symbol: func_ov024_021e6798; size: 0x18.
// Field roles are unresolved; offsets describe the observed layout.
extern "C" ARM int Combatant_IsExcludedFromActionResolution(void* object)
{
    unsigned char* record = *(unsigned char**)((unsigned char*)object + 0x138);
    return (*(unsigned int*)(record + 0x18) & 0x2000) != 0;
}
