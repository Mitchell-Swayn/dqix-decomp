#pragma force_active on

struct WindowCanvasOwner;
struct WindowCanvasRecord;
extern "C" WindowCanvasRecord *Window_FindActiveCanvasById(WindowCanvasOwner *, unsigned);
extern "C" void Graphics_SubmitTransformedCellToOam(void *, void *);

// Original: arm9/ov023 @ 0x021E6A90; symbol: func_ov023_021e6a90; size: 0x74.
extern "C" void Menu_DrawCanvasAccessorySprite(void *owner)
{
    char *self = (char *)owner;
    if (*(unsigned char *)(self + 0x1371) == 6) return;
    char *canvas = (char *)Window_FindActiveCanvasById((WindowCanvasOwner *)(self + 0xAC), 17);
    if (!canvas) return;
    short left = *(short *)(canvas + 0xAC);
    short top = *(short *)(canvas + 0xAE);
    char *sprites = *(char **)(self + 0x1364);
    *(int *)(sprites + 0x1F4) = ((int)(short)(left * 8) + 10) * 4096;
    *(int *)(sprites + 0x1F8) = ((int)(short)(top * 8) + 3) * 4096;
    Graphics_SubmitTransformedCellToOam(*(void **)(self + 0x135C), sprites + 0x1E0);
}
