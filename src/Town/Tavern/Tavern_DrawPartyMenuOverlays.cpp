#include <globaldefs.h>
ARM
// Original: arm9/ov003:021604d0; When record byte +0x4a3 is set, runs the two record processing helpers in sequence; caller is func_ov003_0215fce8.
extern "C" void Graphics_DrawAvailableTextureGeometryLabels(void *);
extern "C" void Tavern_DrawCharacterRowMarkers(void *);
extern "C" void Tavern_DrawPartyMenuOverlays(unsigned char *p) {
    if (p[0x4a3] == 0) return;
    Graphics_DrawAvailableTextureGeometryLabels(p);
    Tavern_DrawCharacterRowMarkers(p);
}
