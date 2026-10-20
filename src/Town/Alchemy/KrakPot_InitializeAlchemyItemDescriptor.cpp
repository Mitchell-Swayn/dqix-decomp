#include <globaldefs.h>
ARM
extern "C" void ZoneSerializedRecord_Reset(char *);
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov006 @ 0x02157C78; symbol: func_ov006_02157c78; size: 0x48.
extern "C" void KrakPot_InitializeAlchemyItemDescriptor(char *p) {
    ZoneSerializedRecord_Reset(p);
    memset(p + 0x20, 0, 0x20);
    memset(p + 0x40, 0, 0x30);
    *(void **)p = p + 0x20;
    *(void **)(p + 4) = p + 0x40;
    *(short *)(p + 0x70) = -1;
}
