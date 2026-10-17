#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" int Object_ReadIndexedBitAtOffset8EC(unsigned char* state,int bit);
extern "C" unsigned char data_ov000_02182ac5[];
// Original: arm9/ov000 @ 0x021564CC; symbol: func_ov000_021564cc; size: 0x8C.
extern "C" bool GameState_TestFlagD0RandomRoll(void *random, int index) {
    void *state = _ZN9GameState11GetInstanceEv();
    int valid;
    if (index >= 0 && index <= 3) valid = 1;
    else valid = 0;
    if (!valid) return 0;
    char *object = (char*)GameState_GetObjectWithFlag100(state, index);
    if (!object) return 0;
    int enabled = Object_ReadIndexedBitAtOffset8EC(*(unsigned char**)(object + 0x150), 0xd0);
    if (enabled == 0) return 0;
    unsigned char *values = *(unsigned char**)(object + 0x150);
    return _Z13NextRandomMaxP6Randomi(random, data_ov000_02182ac5[*(unsigned*)(values + 0x950)]) == 1;
}
