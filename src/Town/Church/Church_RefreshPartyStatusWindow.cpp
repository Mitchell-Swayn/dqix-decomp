#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned int);
extern "C" void Church_FormatPartyStatusList(void*, void*, int);
extern "C" int Window_ReplaceCanvasTextById(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov003 @ 0x0215BE20; symbol: Unclassified_ClearStateBufferAndLoadReadyRecord2; size: 0x50.
// Clears 0x960 bytes at self+0x7C, initializes the buffer, and loads ready record 2 into self+0xF4.
extern "C" void Church_RefreshPartyStatusWindow(void* self) {
    memset(*(void**)((char*)self + 0x7C), 0, 0x960);
    Church_FormatPartyStatusList(self, *(void**)((char*)self + 0x7C), 0);
    Window_ReplaceCanvasTextById((char*)self + 0xF4, 2, *(void**)((char*)self + 0x7C), 1, 0);
}
