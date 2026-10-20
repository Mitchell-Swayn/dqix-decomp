#include <globaldefs.h>
extern "C" void* memset(void*, int, unsigned);
extern "C" void* BattleMenu_GetSelectedPartyCommandRecord(char*);
extern "C" void BattleMenu_UpdateSpellDescriptionWindow(void*, void*);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void BattleMenu_AppendVisibleSpellNames(void*, void*, void*);
extern "C" int Window_ReplaceCanvasTextById(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x02178CBC; symbol: func_ov000_02178cbc; size: 0x6C.
extern "C" void Object_BuildAlternateSelectionBufferAndLoadOwnerRecord(void* object) {
    void* entry = BattleMenu_GetSelectedPartyCommandRecord((char*)object);
    BattleMenu_UpdateSpellDescriptionWindow(object, entry);
    unsigned char* owner = (unsigned char*)TextContext_GetSharedInstance();
    char* buffer = *(char**)(owner + 0x5c);
    memset(buffer, 0, 0x960);
    BattleMenu_AppendVisibleSpellNames(object, entry, buffer);
    Window_ReplaceCanvasTextById((char*)object + 0x188, 0xf, buffer, 1, 0);
}
