#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
struct GameResources;
extern "C" GameResources *GameResources_GetInstance(void);
extern "C" void GameState_MarkOverlayRecordReadyForType3(void *object);
// Original: arm9/ov003 @ 0x0217F194; symbol: func_ov003_0217f194; size: 0x24.
extern "C" void GameState_InitializeResourcesThenMarkOverlayRecord(void *object) {
    _ZN9GameState11GetInstanceEv();
    GameResources_GetInstance();
    void *record = *(void **)((char *)object + 0xc);
    if (record)
        GameState_MarkOverlayRecordReadyForType3(record);
}
