#include <globaldefs.h>
// Original: arm9/ov024 @ 0x021EDA60; symbol: func_ov024_021eda60; size: 0x18.
// Field roles are unresolved; offsets describe the observed layout.
extern "C" ARM int Combatant_TestPrimaryStatusFlagBit9(void* object)
{
    unsigned char* record = *(unsigned char**)((unsigned char*)object + 0x138);
    return (*(unsigned int*)(record + 0x14) & 0x200) != 0;
}
