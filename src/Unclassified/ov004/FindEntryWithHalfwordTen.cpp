#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void**, unsigned short);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
// Original: arm9/ov004 @ 0x02157054; symbol: func_ov004_02157054; size: 0x34.
extern "C" void* FindEntryWithHalfwordTen(void* state, unsigned short key) {
    void* head = func_ov011_021849c8(state);
    void* entry = func_ov023_021f6880((void**)head, key);
    if (entry && OV023_ReadHalfwordField04(entry) == 0x10)
        return entry;
    return 0;
}
