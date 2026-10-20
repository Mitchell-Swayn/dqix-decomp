#include <globaldefs.h>
#include <GameState/GameState.h>
// Locate the current profile field in a table of 16-bit identifiers.
// Original: arm9/ov012 @ 0x02184384; symbol: func_ov012_02184384; size: 0x50.
extern "C" int ProfileEditor_FindCurrentTitleIndex(const unsigned short* identifiers, int count) {
    unsigned char* state = reinterpret_cast<unsigned char*>(GameState::GetInstance()) + 0x569c;
    int value = (int)(*(unsigned int*)(state + 4) << 2) >> 21;
    for (int i = 0; i < count; ++i) if (identifiers[i] == value) return i;
    return -1;
}
