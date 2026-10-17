#include <globaldefs.h>
ARM
extern "C" unsigned char *data_ov031_02250bfc;
extern "C" void Network_UnlinkNodeAndReleaseRecords(void *object);
extern "C" void OV031_WriteWordField08(void *self, unsigned int value);
extern "C" void func_ov031_02225580(void);
// Original: arm9/ov031 @ 0x02223F6C; symbol: func_ov031_02223f6c; size: 0x34.
extern "C" void Object_InitializeGlobalComponents(void) {
    unsigned char *object = data_ov031_02250bfc;
    Network_UnlinkNodeAndReleaseRecords(*(void **)(object + 0x114));
    object = data_ov031_02250bfc;
    OV031_WriteWordField08(*(void **)(object + 0x118), (unsigned int)func_ov031_02225580);
}
