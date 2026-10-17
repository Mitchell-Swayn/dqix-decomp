#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned int GameState_ReadAttributeBits12To19(void* state, int identifier);
extern "C" int Object_ReadIndexedBitAtOffset8EC(void* object, int identifier);
extern "C" const unsigned int data_020e8c00[];

// Original: arm9/main @ 0x02085AB8; symbol: func_02085ab8; size: 0xD0.
extern "C" unsigned int ReadDescriptorDependentStateValue(unsigned char* object, unsigned char* descriptor)
{
    void* state = GameState::GetInstance();
    if (((*(unsigned int*)(descriptor + 0x18) << 16) >> 28) == 2) {
        if ((object[0x8f8] & 0x80) == 0) return 0;
        return GameState_ReadAttributeBits12To19(state, 0x67);
    }
    unsigned int key = 0x21;
    if (*(short*)(object + 0x2ac) > 0)
        key = (*(unsigned int*)(object + 0x29c) << 23) >> 27;
    const unsigned int* map = data_020e8c00;
    int identifier = -1;
    while (*map != 0xffffffff) {
        if (*map == key) {
            identifier = (short)map[1];
            break;
        }
        map += 2;
    }
    unsigned int result = 0;
    if (identifier != -1 && Object_ReadIndexedBitAtOffset8EC(object, identifier) != 0)
        result += GameState_ReadAttributeBits12To19(state, identifier);
    return result;
}
