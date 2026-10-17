#include <globaldefs.h>
ARM
extern "C" void Memory_InitializeRecordSentinel(void*);
extern "C" void AddUniqueFourSlotRecord(void*, void*);
// Original: arm9/ov025 @ 0x021EB148; symbol: func_ov025_021eb148; size: 0x40.
extern "C" void OV025_InitializeAndApplyParameterTriple(void* object, unsigned short value1, unsigned short value2, unsigned char value3) {
    unsigned char parameters[0xc];
    Memory_InitializeRecordSentinel(parameters);
    *(unsigned short*)(parameters + 4) = value1;
    *(unsigned short*)(parameters + 6) = value2;
    parameters[8] = value3;
    AddUniqueFourSlotRecord(object, parameters);
}
