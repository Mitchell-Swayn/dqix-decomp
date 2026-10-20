#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void *TextContext_GetSharedInstance(void);
extern "C" void BattleMenu_AppendPartyCommandOptions(void *, void *);
extern "C" int Window_ReplaceCanvasTextById(void *, unsigned int, void *, unsigned int, unsigned char);
// Original: arm9/ov000 @ 0x02177330; symbol: func_ov000_02177330; size: 0x4C.
extern "C" void BattleMenu_RefreshPartyCommandPanelText(void *owner) {
    void *buffer = *(void **)((char *)TextContext_GetSharedInstance() + 0x5c);
    memset(buffer, 0, 0x960);
    BattleMenu_AppendPartyCommandOptions(owner, buffer);
    Window_ReplaceCanvasTextById((char *)owner + 0x188, 1, buffer, 1, 0);
}
