struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#pragma force_active on
struct Record;
struct Owner;
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void Graphics_PositionAndSubmitSpriteCell(int, int, void*, unsigned, unsigned char, unsigned char);
// Original: arm9/ov002 @ 0x0215AAA4; symbol: func_ov002_0215aaa4; size: 0xbc.
// Positions the four command-slot sprite cells relative to canvas 33 in eight-pixel units.
extern "C" void PartyMenu_PositionCommandSlotSprites(char* self) {
    char* canvas = (char*)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(self + 0xec8)), 33);
    if (canvas) {
        short x = (short)(*(short*)(canvas + 0xac) * 8) + 6;
        short y = (short)(*(short*)(canvas + 0xae) * 8);
        short positions[4];
        positions[0] = y + 26;
        positions[1] = y + 50;
        positions[2] = y + 74;
        positions[3] = y + 98;
        for (unsigned char i = 0; i < 4; ++i) {
            Graphics_PositionAndSubmitSpriteCell(x, positions[i], *(void**)(self + 0x1a68), (unsigned short)(i + 7), 255, 255);
        }
    }
}
