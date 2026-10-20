#include <globaldefs.h>
extern "C" void* BattleMenu_GetSelectedPartyCommandRecord(char*);
extern "C" void* BattleMenu_UpdateCarriedItemDescriptionWindow(void*, void*);
extern "C" unsigned int TextContext_GetSharedInstance(void*);
extern "C" void* memset(void*, int, unsigned);
extern "C" void Graphics_FormatPagedRecordNamesWithStyle(void*, void*, void*);
extern "C" int Window_ReplaceCanvasTextById(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x021795E0; symbol: func_ov000_021795e0; size: 0x6C.
extern "C" ARM void Ov000_BuildIndexedDescription(void* owner) {
    void* entry = BattleMenu_GetSelectedPartyCommandRecord((char*)owner);
    void* context = BattleMenu_UpdateCarriedItemDescriptionWindow(owner, entry);
    char* buffer = *(char**)(TextContext_GetSharedInstance(context) + 0x5c);
    memset(buffer, 0, 0x960);
    Graphics_FormatPagedRecordNamesWithStyle(owner, entry, buffer);
    Window_ReplaceCanvasTextById((char*)owner + 0x188, 0x11, buffer, 1, 0);
}
