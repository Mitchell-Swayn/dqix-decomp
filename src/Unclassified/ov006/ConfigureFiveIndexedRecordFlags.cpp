#include <globaldefs.h>
ARM
extern "C" unsigned char* Resource_FindIndexedRecordByHalfword(void*, int);
// Original: arm9/ov006 @ 0x021573C8; symbol: func_ov006_021573c8; size: 0x94.
extern "C" void ConfigureFiveIndexedRecordFlags(void *self) {
    unsigned char *record = Resource_FindIndexedRecordByHalfword(self, 0x50);
    if (record) record[0x16] &= ~1;
    record = Resource_FindIndexedRecordByHalfword(self, 0x4f);
    if (record) record[0x16] &= ~1;
    record = Resource_FindIndexedRecordByHalfword(self, 0x0e);
    if (record) record[0x16] &= ~1;
    record = Resource_FindIndexedRecordByHalfword(self, 0x0f);
    if (record) record[0x16] &= ~1;
    record = Resource_FindIndexedRecordByHalfword(self, 0x15);
    if (record) record[0x16] |= 1;
}
