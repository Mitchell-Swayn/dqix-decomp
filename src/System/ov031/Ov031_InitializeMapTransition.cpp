#include <globaldefs.h>
extern "C" unsigned char data_ov031_02290cb8[];
extern "C" void Graphics_LoadMainBG2CharacterPaletteAndScreen();
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive();
extern "C" void func_ov031_0222336c(unsigned, int, unsigned);
extern "C" void func_ov031_02223518(void*);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned);
extern "C" void func_ov031_02222b0c(unsigned);
extern "C" void System_ResolveGlobalGroupEntry(unsigned);
extern "C" void func_ov031_02231cb4();
extern "C" void SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02231BB0; symbol: func_ov031_02231bb0; size: 0x5C.
extern "C" ARM void Ov031_InitializeMapTransition() {
    data_ov031_02290cb8[0] = 0;
    Graphics_LoadMainBG2CharacterPaletteAndScreen();
    System_ConvertSharedRegionByteToIndexPlusFive();
    func_ov031_0222336c(0x37, -1, 0);
    func_ov031_02223518((void*)2);
    Graphics_SubmitIndexedConfiguredBuffer(0x24);
    func_ov031_02222b0c(0);
    System_ResolveGlobalGroupEntry(0xb);
    SetMainLoopCallback(func_ov031_02231cb4);
}
