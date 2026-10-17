#include <globaldefs.h>
#include <Resource/GameResources.h>
extern "C" void *ReadGlobalValueAt020FB3F0(void);
extern "C" void _ZN6Zone3D27RequestBMDJObjectStateResetEii(void *, int, int);
// Original: arm9/ov017 @ 0x021CFE84; symbol: func_ov017_021cfe84; size: 0x4C.
extern "C" void Ov017_ResetZoneObjectStateIfAllowed(void *unused, char *request) {
    void *global = ReadGlobalValueAt020FB3F0();
    if (*(unsigned short *)(request + 4) != *(unsigned short *)global) return;
    char *resources = (char *)GameResources_GetInstance();
    void *state = *(void **)(resources + 0x3734);
    if (*(unsigned char *)((char *)state + 3) != 0) return;
    _ZN6Zone3D27RequestBMDJObjectStateResetEii(global,
        *(unsigned short *)(request + 8), *(unsigned short *)(request + 6));
}
