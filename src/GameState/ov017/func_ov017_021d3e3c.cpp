#include <globaldefs.h>
ARM
extern "C" void *Object_GetGlobalConnectionState(void);
extern "C" bool TestActiveWordAndGlobalStateNonzero(unsigned int *p);
extern "C" void *ReadGlobalAt02100044(void);
struct Object;
extern "C" void MoveQueuedRecordAndApplySourceValue(Object *, const void *, short);
// Original: arm9/ov017 @ 0x021D3E3C; symbol: func_ov017_021d3e3c; size: 0x40.
extern "C" void func_ov017_021d3e3c(unsigned char value) {
    unsigned int *state = (unsigned int *)Object_GetGlobalConnectionState();
    if (TestActiveWordAndGlobalStateNonzero(state)) return;
    Object *object = (Object *)ReadGlobalAt02100044();
    unsigned char record[0x14];
    record[0] = 0xba;
    record[4] = value;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
