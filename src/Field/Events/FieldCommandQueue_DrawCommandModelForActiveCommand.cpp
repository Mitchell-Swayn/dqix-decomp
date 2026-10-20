#include <globaldefs.h>
#pragma force_active on
ARM
extern "C" void DrawEmbeddedObjectIfStateThree(unsigned char*);
// Original: arm9/ov017 @ 0x021A3B00; symbol: func_ov017_021a3b00; size: 0x30.
// Draws the embedded command object for an active type-22 record.
extern "C" void FieldCommandQueue_DrawCommandModelForActiveCommand(void* unused, unsigned int recordAddress)
{
    unsigned char* record=(unsigned char*)recordAddress;
    if (!record) return;
    if (record[1]) return;
    switch (*(signed char*)record) {
    case 22: DrawEmbeddedObjectIfStateThree(record); break;
    }
}
