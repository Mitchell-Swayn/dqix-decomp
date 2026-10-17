#include <globaldefs.h>
ARM
extern "C" void *OV017_GetEmbeddedField1C(void *);
extern "C" void func_ov017_021b86e0(void *);
// Original: arm9/ov017 @ 0x021CBC0C; symbol: func_ov017_021cbc0c; size: 0x3C.
extern "C" void Graphics_ProcessLightingEntryIfIdMatches(int ignored0, void *record, int ignored2, unsigned char *owner) {
    void *entry = *(void **)((unsigned char *)owner + 0x3718);
    void *embedded = OV017_GetEmbeddedField1C(entry);
    if (embedded == 0) return;
    if (*(unsigned short *)((unsigned char *)embedded + 8) != *(unsigned short *)((unsigned char *)record + 4)) return;
    func_ov017_021b86e0(entry);
}
