#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void *BattleMenu_GetSelectedPartyCommandRecord(char *);
extern "C" void GameState_BuildIndexedTextAndEnsureReadyRecord(void *, void *);
extern "C" void *TextContext_GetSharedInstance(void);
extern "C" void BattleMenu_AppendEquipmentChoicePage(void *, void *);
extern "C" int Window_ReplaceCanvasTextById(void *, unsigned int, void *, unsigned int, unsigned char);
// Original: arm9/ov000 @ 0x0217819C; symbol: func_ov000_0217819c; size: 0x5C.
extern "C" void BattleMenu_RefreshEquipmentChoicePanelText(void *owner) {
    void *record = BattleMenu_GetSelectedPartyCommandRecord((char *)owner);
    GameState_BuildIndexedTextAndEnsureReadyRecord(owner, record);
    void *buffer = *(void **)((char *)TextContext_GetSharedInstance() + 0x5c);
    memset(buffer, 0, 0x960);
    BattleMenu_AppendEquipmentChoicePage(owner, buffer);
    Window_ReplaceCanvasTextById((char *)owner + 0x188, 7, buffer, 1, 0);
}
