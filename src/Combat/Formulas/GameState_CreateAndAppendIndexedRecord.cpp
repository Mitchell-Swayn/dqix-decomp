#include <globaldefs.h>
ARM

extern "C" ARM void *Combat_ClearCurrentResultNodeSlot(unsigned char *p);
extern "C" ARM void Combat_AppendResultMessage(void *, void *, unsigned int);
extern "C" ARM void Combat_AppendTargetResultToCategoryList(void *list, void *node, int value);

// Original: arm9/ov024 @ 0x021E8CA0; symbol: func_ov024_021e8ca0; size: 0x5C.
extern "C" void *GameState_CreateAndAppendIndexedRecord(void *self, unsigned int key) {
    void *record = Combat_ClearCurrentResultNodeSlot(*(unsigned char **)((char *)self + 0x10));
    if (record == 0) {
        return 0;
    }
    Combat_AppendResultMessage(*(void **)((char *)self + 0x10), record, key);
    Combat_AppendTargetResultToCategoryList(*(void **)((char *)self + 0xc), record, 1);
    unsigned char *counter = (unsigned char *)*(void **)((char *)self + 0x10) + 0x8e02;
    *counter = *counter + 1;
    return record;
}
