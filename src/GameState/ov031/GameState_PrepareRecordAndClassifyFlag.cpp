#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void func_ov031_02243b34(void *record);
// Original: arm9/ov031 @ 0x022436E0; symbol: func_ov031_022436e0; size: 0x28.
extern "C" int GameState_PrepareRecordAndClassifyFlag(unsigned char *record) {
    _ZN9GameState11GetInstanceEv();
    func_ov031_02243b34(record);
    return record[0x36] != 0 ? 2 : 1;
}
