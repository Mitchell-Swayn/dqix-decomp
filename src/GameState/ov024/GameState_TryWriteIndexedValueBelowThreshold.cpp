#include <globaldefs.h>
ARM
extern "C" void* FindIndexedGameStateObjectWithFlag400(unsigned index);
// Original: arm9/ov024 @ 0x021F331C; symbol: func_ov024_021f331c; size: 0x4C.
extern "C" int GameState_TryWriteIndexedValueBelowThreshold(const unsigned* index, unsigned short value, unsigned unused, unsigned* found, unsigned short* output) {
    void* object = FindIndexedGameStateObjectWithFlag400(*index);
    if (object == 0) return 0;
    unsigned* state = (unsigned*)((char*)*(void**)((char*)object + 0x138) + 0x58);
    int mode = (int)(*state << 17) >> 29;
    if (mode >= 2) return 0;
    *found = 1;
    *output = value;
    return 1;
}
