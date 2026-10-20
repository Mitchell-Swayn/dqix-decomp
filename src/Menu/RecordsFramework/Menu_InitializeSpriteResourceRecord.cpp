#include <globaldefs.h>
extern "C" void MenuRecord_ResetHeader(void*);
extern "C" void Graphics_InitializeSpriteResourceBuffers(unsigned char*);
extern "C" void* memset(void*, int, unsigned);
extern "C" void Menu_StageCompletedNamedSpriteResource(void*, void*);
// Original: arm9/ov023 @ 0x021FA760; symbol: func_ov023_021fa760; size: 0x74.
extern "C" ARM int Menu_InitializeSpriteResourceRecord(void* record, void* owner, unsigned short valueA, unsigned short valueB, unsigned first, unsigned second, unsigned mode) {
    MenuRecord_ResetHeader(record);
    *(unsigned short*)((char*)record + 4) = 10;
    *(unsigned short*)((char*)record + 6) = valueA;
    *(unsigned short*)((char*)record + 8) = valueB;
    *(unsigned short*)((char*)record + 0xa) = 0;
    *(unsigned*)((char*)record + 0x20) = first;
    *(unsigned*)((char*)record + 0x10) = second;
    Graphics_InitializeSpriteResourceBuffers((unsigned char*)record + 0x24);
    memset((char*)record + 0x78, 0, 0x10);
    *((unsigned char*)record + 0x74) = (unsigned char)mode;
    Menu_StageCompletedNamedSpriteResource(record, owner);
    return 1;
}
