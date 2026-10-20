#include <globaldefs.h>
ARM
extern "C" void* BattleMenu_GetSelectedPartyCommandRecord(char*);
extern "C" void* BattleMenu_UpdateVocationActionDescriptionWindow(void*, int);
extern "C" unsigned int TextContext_GetSharedInstance(void*);
extern "C" void* memset(void*, int, unsigned);
extern "C" void Graphics_AppendPagedPartyStateText(void*, void*, void*);
extern "C" int Window_ReplaceCanvasTextById(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x02179C6C; symbol: LoadReadyRecord15FromIndexedEntry; size: 0x70.
// Finds the current indexed entry, prepares owner state, clears its scratch buffer, builds data from the entry, and loads ready record type 0x15.
extern "C" void BattleMenu_RefreshVocationActionWindow(void* self, int parameter) {
    void* entry = BattleMenu_GetSelectedPartyCommandRecord((char*)self);
    void* result = BattleMenu_UpdateVocationActionDescriptionWindow(self, parameter);
    unsigned char* state = (unsigned char*)TextContext_GetSharedInstance(result);
    void* scratch = *(void**)(state + 0x5c);
    memset(scratch, 0, 0x960);
    Graphics_AppendPagedPartyStateText(self, entry, scratch);
    Window_ReplaceCanvasTextById((char*)self + 0x188, 0x15, scratch, 1, 0);
}
