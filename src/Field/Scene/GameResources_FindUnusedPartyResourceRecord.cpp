#include <globaldefs.h>
ARM
// Original: arm9/ov017:021a11b4; Searches four signed halfword entries at self +0x12c8 with stride 0x5ec and returns the first negative entry address, or null.
extern "C" void* GameResources_FindUnusedPartyResourceRecord(void* self) {
    char* entries = (char*)self;
    entries += 0x2C8;
    entries += 0x1000;
    for (int i = 0; i < 4; ++i) {
        char* entry = entries + i * 0x5EC;
        if (*(short*)entry < 0) return entries + i * 0x5EC;
    }
    return 0;
}
