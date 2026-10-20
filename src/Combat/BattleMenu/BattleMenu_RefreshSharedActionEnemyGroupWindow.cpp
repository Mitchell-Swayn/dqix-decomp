#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void*);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void BattleMenu_AppendSharedActionEnemyGroupNames(void*, unsigned int, unsigned int, void*);
extern "C" int Window_ReplaceCanvasTextById(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x0217A628; symbol: LoadReadyRecord19FromOwnerBuffer; size: 0x60.
// For nonzero ID, clears owner scratch buffer +0x5C, builds data there, loads ready record type 0x19, and refreshes owner +0x188.
extern "C" void BattleMenu_RefreshSharedActionEnemyGroupWindow(void* owner, unsigned int id, unsigned int arg) {
    if (!id) return;
    unsigned char* p = (unsigned char*)TextContext_GetSharedInstance(owner);
    void* buffer = *(void**)(p + 0x5c);
    memset(buffer, 0, 0x960);
    BattleMenu_AppendSharedActionEnemyGroupNames(owner, id, arg, buffer);
    Window_ReplaceCanvasTextById((char*)owner + 0x188, 0x19, buffer, 1, 0);
}
