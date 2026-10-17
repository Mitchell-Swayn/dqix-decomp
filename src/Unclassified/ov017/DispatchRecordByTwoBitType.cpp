#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov017_021d8498[];
extern "C" int func_ov017_021d451c(void*, void*);
extern "C" int func_ov017_021d45e0(void*, void*);
struct RecordTag { unsigned char type:2; };
// Original: arm9/ov017 @ 0x021C912C; symbol: func_ov017_021c912c; size: 0x3C.
extern "C" int DispatchRecordByTwoBitType(void* unused, void* record) {
    unsigned type = ((RecordTag*)((char*)record + 4))->type;
    void* global = data_ov017_021d8498;
    if (type == 0)
        return func_ov017_021d451c(global, (char*)record + 6);
    if (type == 1)
        return func_ov017_021d45e0(global, (char*)record + 6);
    return (int)global;
}
