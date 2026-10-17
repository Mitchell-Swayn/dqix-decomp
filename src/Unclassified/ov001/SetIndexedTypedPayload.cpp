#include <globaldefs.h>
ARM
extern "C" int SetPayloadForTypeTwoOrSix(unsigned int* object, unsigned int type, unsigned int payload, unsigned int count);

// Original: arm9/ov001 @ 0x02164248; symbol: func_ov001_02164248; size: 0x34.
// Validates a 32-entry index before dispatching the typed payload setter.
extern "C" int SetIndexedTypedPayload(unsigned char* records, int index, unsigned int type, unsigned int payload, unsigned int count)
{
    if (index < 0 || index >= 32) return 0;
    return SetPayloadForTypeTwoOrSix((unsigned int*)(records + index * 16), type, payload, count);
}
