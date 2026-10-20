#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021BBBE4; symbol: Resource_GetRecordPointerAtOffsetA0; size: 0x8.
// Returns the record address at offset 0xa0; resource-loading callers use this adjusted record pointer.
extern "C" void* FieldEvent_GetInEventResultDescriptor(void* record) {
    return (unsigned char*)record + 0xa0;
}
