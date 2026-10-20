#include <globaldefs.h>
ARM
extern "C" void Church_DrawServiceMenu(void*);
// Original: arm9/ov017 @ 0x021BABE0; symbol: Resource_UpdateActiveWindowFromField1C; size: 0x18.
// Passes the nonnull pointer at object offset 0x1c to UpdateActiveIndexedResourceWindow.
extern "C" void Field_UpdateChurchServiceWindowMask(void* p) { void* q = *(void**)((char*)p + 0x1c); if (q) Church_DrawServiceMenu(q); }
