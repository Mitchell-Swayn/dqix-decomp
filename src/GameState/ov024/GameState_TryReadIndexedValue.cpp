#include <globaldefs.h>
ARM
extern "C" void* FindIndexedGameStateObjectWithFlag400(unsigned index);
// Original: arm9/ov024 @ 0x021F59C4; symbol: func_ov024_021f59c4; size: 0x44.
extern "C" int GameState_TryReadIndexedValue(const unsigned* index, unsigned short value, unsigned unused, unsigned* found, unsigned short* output) {
    void* object = FindIndexedGameStateObjectWithFlag400(*index);
    if (object == 0) return 0;
    void* entry = *(void**)((char*)object + 0x138);
    if (*(unsigned short*)((char*)entry + 2) != 0) return 0;
    *found = 1;
    *output = value;
    return 1;
}
