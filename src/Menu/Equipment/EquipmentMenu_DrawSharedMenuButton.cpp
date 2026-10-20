#include <globaldefs.h>
class GameResources;
extern "C" GameResources* GameResources_GetInstance();
extern "C" unsigned Field_GetSharedSubscreenInstance(void*);
extern "C" void Menu_DrawEquipmentPositionMarker(char*,int,int);
// Original: arm9/ov005 @ 0x0215A3BC; symbol: func_ov005_0215a3bc; size: 0x5C.
extern "C" void EquipmentMenu_DrawSharedMenuButton(char* self) {
    short x = 0x80;
    short y = 0xb0;
    unsigned flags = *(unsigned*)(self + 0x3dcc);
    if (flags & 0x80000) {
        x += 1;
        y += 1;
        *(unsigned*)(self + 0x3dcc) = flags & ~0x80000;
    }
    char* resource = (char*)GameResources_GetInstance();
    void* field = *(void**)(resource + 0x3708);
    char* recordOwner = (char*)Field_GetSharedSubscreenInstance(field);
    Menu_DrawEquipmentPositionMarker(recordOwner,x,y);
}
