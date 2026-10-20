#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void *TextContext_GetSharedInstance(void *);
extern "C" void BattleMenu_AppendSessionOptions(void *, void *);
extern "C" int Window_ReplaceCanvasTextById(void *, unsigned int, void *, unsigned int, unsigned char);
// Original: arm9/ov000 @ 0x02177558; symbol: Resource_RebuildOwnerBufferAndRefreshReadyRecord; size: 0x4C.
// Clears and rebuilds the owner buffer, then loads a matching ready record and refreshes owner fields.
extern "C" void Resource_RebuildOwnerBufferAndRefreshReadyRecord(void *owner) {
 char *buffer = *(char **)((char *)TextContext_GetSharedInstance(owner) + 0x5c);
 memset(buffer, 0, 0x960);
 BattleMenu_AppendSessionOptions(owner, buffer);
 Window_ReplaceCanvasTextById((char *)owner + 0x188, 2, buffer, 1, 0);
}
