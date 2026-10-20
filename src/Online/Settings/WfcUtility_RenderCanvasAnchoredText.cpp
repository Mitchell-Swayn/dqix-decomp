#include <globaldefs.h>
#pragma optimize_for_size off
struct Direction { signed char x, y; };
extern "C" void TextLayout_RenderAnchoredTextInDirection(unsigned*, int, int, unsigned, unsigned, unsigned, Direction);
#pragma force_active on
// Original: arm9/ov031 @ 0x0223C7E8; symbol: func_ov031_0223c7e8; size: 0xB0.
// Converts the canvas font's orientation code to a signed text direction and forwards the rendering arguments.
extern "C" void WfcUtility_RenderCanvasAnchoredText(unsigned char* canvas, int x, int y, unsigned value, unsigned flags, unsigned data)
{
    unsigned char* text = *(unsigned char**)(canvas + 0x1c);
    Direction direction = { 0, 0 };
    unsigned char* font = *(unsigned char**)text;
    unsigned char* fontData = *(unsigned char**)(font + 8);
    switch (fontData[7])
    {
    case 0: case 7: direction.x = 1; break;
    case 1: case 2: direction.y = 1; break;
    case 3: case 4: direction.x = -1; break;
    case 5: case 6: direction.y = -1; break;
    }
    TextLayout_RenderAnchoredTextInDirection((unsigned*)(canvas + 0x18), x, y, value, flags, data, direction);
}
