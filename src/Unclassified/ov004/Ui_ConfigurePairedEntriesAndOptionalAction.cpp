#include <globaldefs.h>
ARM
extern "C" void func_ov023_021f6600(void*, unsigned, unsigned);
extern "C" void GameState_AppendValueAndSetNodeFlags(void*, unsigned, unsigned);
extern "C" void func_ov011_021848a0(void*, unsigned);
extern "C" void* data_ov004_02171030;
// Original: arm9/ov004 @ 0x02169ADC; symbol: func_ov004_02169adc; size: 0x70.
extern "C" int Ui_ConfigurePairedEntriesAndOptionalAction(void* self) {
    func_ov023_021f6600(self, 0x1e, 0x18);
    func_ov023_021f6600(self, 0x1f, 0x18);
    GameState_AppendValueAndSetNodeFlags(self, 2, 8);
    void* state = *(void**)((char*)data_ov004_02171030 + 0x190);
    if (state == 0) return 0;
    if (*(unsigned char*)state != 0) func_ov011_021848a0(self, 0x48);
    return 0;
}
