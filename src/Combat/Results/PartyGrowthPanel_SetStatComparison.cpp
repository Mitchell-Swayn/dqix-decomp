#include <globaldefs.h>
ARM
// Original: arm9/ov023:021d8e4c; Stores the value, copies two 20-byte owner structures, records whether both owner pointers are set, and writes mode 2.
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" unsigned int Window_GetCanvasStackDepth(char*);
extern "C" void PartyGrowthPanel_SetStatComparison(char* object, unsigned value, const void* a, const void* b) {
    *(unsigned*)(object+0xec)=value;
    memcpy(object+0xf0,a,0x14);
    memcpy(object+0x104,b,0x14);
    unsigned x=Window_GetCanvasStackDepth(object+0x20);
    if (x == 0) object[0x11c] = 0; else object[0x11c] = 1;
    object[0x11a] = 2;
}
