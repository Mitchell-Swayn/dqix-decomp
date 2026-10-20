#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void *TextContext_GetSharedInstance(void *);
extern "C" void BattleMenu_AppendAllyTargetNames(void *, unsigned int, unsigned int, void *);
extern "C" int Window_ReplaceCanvasTextById(void *, unsigned int, void *, unsigned int, unsigned char);
// Original: arm9/ov000 @ 0x02179A14; symbol: Resource_BuildOwnerBufferAndLoadRecord0x12; size: 0x5C.
// Clears the owner buffer, builds it from three inputs, then loads ready record 0x12 and refreshes the owner.
extern "C" void BattleMenu_RefreshAllyTargetWindow(void *owner, unsigned int a, unsigned int b) {
 char *buffer = *(char **)((char *)TextContext_GetSharedInstance(owner) + 0x5c);
 memset(buffer, 0, 0x960);
 BattleMenu_AppendAllyTargetNames(owner, a, b, buffer);
 Window_ReplaceCanvasTextById((char *)owner + 0x188, 0x12, buffer, 1, 0);
}
