#include <globaldefs.h>
ARM
struct State;
extern "C" unsigned char data_ov004_021707d8[];
extern "C" void Ov004_InitializeRecordFields(void *record);
extern "C" void func_ov011_021848a0(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0215B330; symbol: func_ov004_0215b330; size: 0x30.
extern "C" int GameState_InitializeGlobalRecordAndSet39E(State *self) {
    Ov004_InitializeRecordFields(*(void **)(data_ov004_021707d8 + 8));
    func_ov011_021848a0(self, 0x39e);
    return 0;
}
