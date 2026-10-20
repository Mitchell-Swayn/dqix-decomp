#include <globaldefs.h>
THUMB
extern "C" int NetworkSocket_SendToAddress(void *object, void *mode, void *record, unsigned int flags, void *output);
// Original: arm9/ov031 @ 0x02220178; symbol: Record_ConvertFieldsAndNormalizeError; size: 0x18.
// Forwards remapped values to the record conversion helper with flags zero; converts negative results to -4.
extern "C" int WirelessSetup_SendDatagramAndNormalizeError(void *object, void *argument, unsigned int unused, void *mode, void *output) {
    int result = NetworkSocket_SendToAddress(object, mode, output, 0, argument);
    return result >= 0 ? result : -4;
}
