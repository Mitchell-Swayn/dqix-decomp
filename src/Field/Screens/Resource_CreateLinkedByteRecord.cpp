#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void Field_InitializeTravelDestinationMenu(void*);
extern "C" void Field_SetTravelDestinationMenuVariant(void*, int);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned*, unsigned);
// Original: arm9/ov017 @ 0x021A8614; symbol: func_ov017_021a8614; size: 0x5C.
extern "C" void Resource_CreateLinkedByteRecord(unsigned unused, int value, unsigned char byte1, unsigned char byte2, unsigned byte3, unsigned byte4) {
    char* resources = (char*)GameResources_GetInstance() + 0x3000;
    unsigned* list = *(unsigned**)(resources + 0x6fc);
    char* record = *(char**)(resources + 0xb7c);
    Field_InitializeTravelDestinationMenu(record);
    Field_SetTravelDestinationMenuVariant(record, value);
    record[0x18] = byte1;
    record[0x19] = byte2;
    record[0x1a] = byte3;
    record[0x1b] = byte4;
    LinkedQueue_AppendAndMarkActive(list, (unsigned)record);
}
