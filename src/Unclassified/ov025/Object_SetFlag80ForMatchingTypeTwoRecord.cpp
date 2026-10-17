#include <globaldefs.h>
extern "C" unsigned ReadOverlayControlSecondWord();
extern "C" char* ResolveOverrideOrIndexedRecord(char*);
extern "C" void* ReadGlobalAt02108E10();
extern "C" void* TryTransformFirstOrSecondEmbeddedRecord(char*, void*);
// Original: arm9/ov025 @ 0x021EBA60; symbol: func_ov025_021eba60; size: 0x54.
extern "C" void Object_SetFlag80ForMatchingTypeTwoRecord(unsigned char* self) {
    char* record = ResolveOverrideOrIndexedRecord((char*)ReadOverlayControlSecondWord());
    void* result = TryTransformFirstOrSecondEmbeddedRecord((char*)ReadGlobalAt02108E10(), (void*)(int)*(short*)record);
    if (result != 0 && (*(unsigned*)((char*)result + 0x14) >> 28) == 2 && ((*(unsigned*)((char*)result + 8) << 22) >> 30) == 1) {
        *(unsigned*)((char*)self + 0x1c4) |= 0x80;
    }
}
