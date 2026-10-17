#include <globaldefs.h>
ARM
extern "C" void Network_UnlinkNodeAndReleaseRecords(void*);
extern "C" void** data_ov031_02250bf0;
// Original: arm9/ov031 @ 0x022238CC; symbol: func_ov031_022238cc; size: 0x40.
extern "C" void Overlay_ClearFourSharedObjects(void) {
    int i = 0;
    do {
        void* object = data_ov031_02250bf0[i];
        if (object != 0) {
            Network_UnlinkNodeAndReleaseRecords(object);
            data_ov031_02250bf0[i] = 0;
        }
        ++i;
    } while (i < 4);
}
