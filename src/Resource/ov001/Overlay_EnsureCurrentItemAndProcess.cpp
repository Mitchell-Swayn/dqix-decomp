#include <globaldefs.h>
extern "C" unsigned char data_ov001_02165828[];
extern "C" void GameState_ProcessPendingOperationIfPresent(void*);
extern "C" void Graphics_RefreshTwentyFourRecordsAndNotify();
extern "C" void Graphics_ResetWindowConfiguration(void*);
// Original: arm9/ov001 @ 0x02153994; symbol: func_ov001_02153994; size: 0x44.
extern "C" int Overlay_EnsureCurrentItemAndProcess() {
    GameState_ProcessPendingOperationIfPresent(data_ov001_02165828);
    if (!*(void**)(data_ov001_02165828 + 0x3c)) Graphics_RefreshTwentyFourRecordsAndNotify();
    void* item = *(void**)(data_ov001_02165828 + 0x3c);
    if (!item) return 0;
    Graphics_ResetWindowConfiguration(item);
    return 1;
}
