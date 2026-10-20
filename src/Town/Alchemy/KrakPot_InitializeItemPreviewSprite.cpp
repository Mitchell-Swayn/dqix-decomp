#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetTilePayloadWithUnitScale(unsigned*);

struct ItemPreviewSprite {
    unsigned char payload[0x70];
    int task;
    short item, x, y;
    unsigned char pending;
};
// Original fallback callers can be weak; retain this entry point in its ROM range.
#pragma force_active on
// Original: arm9/ov006 @ 0x0215479C; symbol: func_ov006_0215479c; size: 0x2C.
// Clears the sprite payload, task and item IDs, coordinates and pending flag.
extern "C" void KrakPot_InitializeItemPreviewSprite(ItemPreviewSprite* sprite)
{
    Graphics_ResetTilePayloadWithUnitScale((unsigned*)sprite);
    sprite->task = -1;
    sprite->item = -1;
    sprite->x = sprite->y = 0;
    sprite->pending = 0;
}

#pragma force_active reset
