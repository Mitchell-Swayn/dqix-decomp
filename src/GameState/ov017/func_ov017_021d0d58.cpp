#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
struct Object;
extern "C" void MoveQueuedRecordAndApplySourceValue(Object *, const void *, short);
// Original: arm9/ov017 @ 0x021D0D58; symbol: func_ov017_021d0d58; size: 0x44.
extern "C" void func_ov017_021d0d58(void) {
    Object *object = (Object *)ReadGlobalAt02100044();
    void *list = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    unsigned char record[0x14];
    record[0] = 0x17;
    *(unsigned int *)(record + 4) = *(unsigned int *)((char *)list + 0x2c94);
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
