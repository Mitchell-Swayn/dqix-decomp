#include <globaldefs.h>
extern "C" void* memset(void*, int, unsigned);
extern "C" void* BattleMenu_GetSelectedPartyCommandRecord(char*);
extern "C" void BattleMenu_UpdateSkillDescriptionWindow(void*, void*);
extern "C" void Text_AppendSelectionPageEntries(char*, char*, char*);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" int Window_ReplaceCanvasTextById(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x02179128; symbol: func_ov000_02179128; size: 0x6C.
extern "C" void BattleMenu_RefreshSkillListWindow(void* object) {
    void* entry = BattleMenu_GetSelectedPartyCommandRecord((char*)object);
    BattleMenu_UpdateSkillDescriptionWindow(object, entry);
    unsigned char* owner = (unsigned char*)TextContext_GetSharedInstance();
    char* buffer = *(char**)(owner + 0x5c);
    memset(buffer, 0, 0x960);
    Text_AppendSelectionPageEntries((char*)object, (char*)entry, buffer);
    Window_ReplaceCanvasTextById((char*)object + 0x188, 0x10, buffer, 1, 0);
}
