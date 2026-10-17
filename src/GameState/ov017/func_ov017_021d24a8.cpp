#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void *ReadGlobalValueAt020FB3F0(void);
struct Object;
extern "C" void MoveQueuedRecordAndApplySourceValue(Object *, const void *, short);
// Original: arm9/ov017 @ 0x021D24A8; symbol: func_ov017_021d24a8; size: 0x48.
extern "C" void func_ov017_021d24a8(unsigned char value) {
    Object *object = (Object *)ReadGlobalAt02100044();
    unsigned char record[0x14];
    unsigned char *payload = record + 4;
    record[0] = 0x1e;
    *payload = value;
    *(unsigned int *)(payload + 4) = *(unsigned short *)ReadGlobalValueAt020FB3F0();
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
