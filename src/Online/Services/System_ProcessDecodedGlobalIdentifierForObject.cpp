#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DecodePersistentIdentifierFields(unsigned int *);
extern "C" void NasAuth_BuildDeviceMetadata(void *, unsigned int *);
// Original: arm9/ov031 @ 0x022175DC; symbol: func_ov031_022175dc; size: 0x28.
extern "C" void System_ProcessDecodedGlobalIdentifierForObject(void *object) {
    unsigned int fields[5];
    WfcUtility_DecodePersistentIdentifierFields(fields);
    NasAuth_BuildDeviceMetadata(object, fields);
}
