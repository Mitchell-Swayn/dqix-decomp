#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void*);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void BattleMenu_AppendAvailableCategoryPage(void*, void*);
extern "C" int Window_ReplaceCanvasTextById(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x02177F28; symbol: Unclassified_ClearOwnerBufferAndLoadReadyRecord6; size: 0x4C.
// Resolves the buffer through ReadWordFieldAtOffset1C(self)+0x5C, clears 0x960 bytes, initializes it, and loads ready record 6 into self+0x188.
extern "C" void BattleMenu_RefreshAvailableCategoryPanelText(void* self) {
    void* data = *(void**)((char*)TextContext_GetSharedInstance(self) + 0x5C);
    memset(data, 0, 0x960);
    BattleMenu_AppendAvailableCategoryPage(self, data);
    Window_ReplaceCanvasTextById((char*)self + 0x188, 6, data, 1, 0);
}
