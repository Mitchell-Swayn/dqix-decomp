#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" void InitializePacked999FieldsAndInvalidIndex(void *);
extern "C" unsigned int GetSelectedEmbeddedTextBufferPointer(void *, int);
// Original: arm9/main @ 0x02083508; symbol: func_02083508; size: 0x4C.
extern "C" void Object_InitializeElevenDataTextSlots(void *object) {
    for (int i = 0; i < 11; ++i) {
        InitializePacked999FieldsAndInvalidIndex((char *)object + 0x194 + i * 0x20);
        unsigned int value = GetSelectedEmbeddedTextBufferPointer(object, i);
        unsigned int *base = (unsigned int *)((char *)object + i * 0x20);
        base[0x198 / 4] = value;
        base[0x194 / 4] = (unsigned int)((char *)object + 0x6f0 + i * 0x20);
    }
}
