#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void *ReadGlobalValueAt02108EA8();
struct E;
extern "C" E *FindKeyAmongFourRecords(E *p,unsigned int key);
extern "C" unsigned short data_ov017_021d7654[];
// Original: arm9/ov017 @ 0x021A1A20; symbol: func_ov017_021a1a20; size: 0xB0.
extern "C" unsigned GameState_AllocateUnusedHighIdentifier(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    E *records = (E *)ReadGlobalValueAt02108EA8();
    unsigned low = 0x7ff8;
    unsigned high = low + 7;
restart:
    if (data_ov017_021d7654[1] > high) data_ov017_021d7654[1] = low;
    for (int i = 0; i < 4; ++i) {
        char *object = (char *)GameState_GetObjectWithFlag100(state,i);
        if (object && data_ov017_021d7654[1] == *(unsigned short *)(object + 0x1b2)) {
            ++data_ov017_021d7654[1];
            goto restart;
        }
    }
    if (FindKeyAmongFourRecords(records,data_ov017_021d7654[1])) {
        ++data_ov017_021d7654[1];
        goto restart;
    }
    return data_ov017_021d7654[1]++;
}
