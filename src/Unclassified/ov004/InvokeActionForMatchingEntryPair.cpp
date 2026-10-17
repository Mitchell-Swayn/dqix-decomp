#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void**, unsigned short);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void func_ov004_0215534c(void*);
// Original: arm9/ov004 @ 0x02155544; symbol: func_ov004_02155544; size: 0x6C.
extern "C" int InvokeActionForMatchingEntryPair(void* state) {
    void* head = func_ov011_021849c8(state);
    void* first = func_ov023_021f6880((void**)head, 0x2c);
    if (!first)
        return 0;
    if (OV023_ReadHalfwordField04(first) != 7)
        return 0;
    void* second = func_ov023_021f6880((void**)head, 3);
    if (!second)
        return 0;
    if (OV023_ReadHalfwordField04(second) != 6)
        return 0;
    func_ov004_0215534c(state);
    return 0;
}
