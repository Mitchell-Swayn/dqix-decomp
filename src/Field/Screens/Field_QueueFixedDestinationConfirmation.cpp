#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void Field_InitializeFixedDestinationConfirmation(signed char*);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned*, unsigned);
// Original: arm9/ov017 @ 0x021A93F0; symbol: func_ov017_021a93f0; size: 0x3C.
extern "C" void Field_QueueFixedDestinationConfirmation(unsigned unused, unsigned value1, unsigned value2) {
    char* resources = (char*)GameResources_GetInstance() + 0x3000;
    unsigned* list = *(unsigned**)(resources + 0x6fc);
    signed char* record = *(signed char**)(resources + 0xb80);
    Field_InitializeFixedDestinationConfirmation(record);
    *(unsigned*)(record + 0xc) = value1;
    *(unsigned*)(record + 0x10) = value2;
    LinkedQueue_AppendAndMarkActive(list, (unsigned)record);
}
