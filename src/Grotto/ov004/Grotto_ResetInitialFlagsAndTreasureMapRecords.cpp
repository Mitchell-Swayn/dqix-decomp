#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void GameState_ResetGrottoAndTreasureMapInitialFlags(void *);
extern "C" void _ZN19TreasureMapMetadata26ClearInitialByteUnknownBitEv(void *);
extern "C" void func_ov011_021848a0(void *, unsigned int);
extern "C" unsigned char data_ov004_02171010;
// Original: arm9/ov004 @ 0x02165B60; symbol: func_ov004_02165b60; size: 0x58.
extern "C" int Grotto_ResetInitialFlagsAndTreasureMapRecords(void *state) {
    GameState_ResetGrottoAndTreasureMapInitialFlags(_ZN9GameState11GetInstanceEv());
    int i = 0;
    while (i < *(unsigned char *)((unsigned char *)*(void **)&data_ov004_02171010 + 0x18F4)) {
        _ZN19TreasureMapMetadata26ClearInitialByteUnknownBitEv((unsigned char *)*(void **)&data_ov004_02171010 + i * 0x1C);
        i++;
    }
    func_ov011_021848a0(state, 0x65);
    return 0;
}
