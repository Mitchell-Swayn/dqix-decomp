struct PartyMenuState;
#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma force_active on
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);
extern "C" void Window_PushTextCanvas(void*, void*, int, int, int, int, int, int);
extern "C" void PartyMenu_ReadCanvasBounds(PartyMenuState*,int,short*,short*,short*,short*);
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*, unsigned, unsigned);
extern "C" void PartyMenu_AppendItemTransferDestinationSlots(void*, void*, int);
// Original: arm9/ov002 @ 0x0215DDBC; symbol: func_ov002_0215ddbc; size: 0xe0.
// Places the inventory preview beside the current canvas and fills its item slots.
extern "C" void PartyMenu_OpenRecipientInventoryPreview(void* owner) {
    char* self = (char*)owner;
    short x = 0, y = 0, width = 1, height = 1;
    PartyMenu_ReadCanvasBounds((PartyMenuState*)(self), *(int*)(self + 0x1bb8) & 0xff,(short*)(&x),(short*)(&y),(short*)(&width),(short*)(&height));
    x += width;
    Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 3);
    PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self), 13, x, y);
    memset(*(void**)(self + 0x1bd0), 0, 0x960);
    PartyMenu_AppendItemTransferDestinationSlots(self, *(char**)(self + 0x1bd0), 0);
    Window_PushTextCanvas(self + 0xec8, *(void**)(self + 0x1bd0), 0, 0, 0, 1, 0, 0);
}
