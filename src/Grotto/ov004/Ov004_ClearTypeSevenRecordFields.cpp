#include <globaldefs.h>
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void**, unsigned short);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void OV023_WriteHalfwordField28(void*, unsigned short);
extern "C" void func_ov023_021f9bb8(void*, unsigned);
// Original: arm9/ov004 @ 0x02164DF4; symbol: func_ov004_02164df4; size: 0x4C.
extern "C" ARM int Ov004_ClearTypeSevenRecordFields(void* state) {
    void** head = (void**)func_ov011_021849c8(state);
    void* record = func_ov023_021f6880(head, 11);
    if (!record) return 0;
    if (OV023_ReadHalfwordField04(record) != 7) return 0;
    OV023_WriteHalfwordField28(record, 0);
    func_ov023_021f9bb8(record, 0);
    return 0;
}
