#include <globaldefs.h>
ARM

extern "C" void MenuRecord_ResetHeader(char *p);
extern "C" void Menu_ResetCatalogue(void *object);

// Original: arm9/ov023 @ 0x021FC1F4; symbol: func_ov023_021fc1f4; size: 0x34.
extern "C" int Item_InitializeWithIdAndKind(void *item, void *owner, unsigned id, unsigned kind) {
    MenuRecord_ResetHeader((char *)item);
    *(unsigned short *)((char *)item + 4) = 0x12;
    *(unsigned short *)((char *)item + 6) = id;
    *(unsigned short *)((char *)item + 8) = kind;
    Menu_ResetCatalogue((char *)item + 0x20);
    return 1;
}
