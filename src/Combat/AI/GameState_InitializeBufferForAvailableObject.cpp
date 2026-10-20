#include <globaldefs.h>
ARM
extern "C" void *Combat_FindIndexedMonsterObject(void *, int);
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov024 @ 0x021F5888; symbol: func_ov024_021f5888; size: 0x54.
extern "C" bool GameState_InitializeBufferForAvailableObject(void **objectList, int index, int ignored, unsigned int *result, void *buffer) {
    void *object = Combat_FindIndexedMonsterObject(*objectList, index);
    if (object == 0) return false;
    unsigned char *entry = (unsigned char *)*(void **)((unsigned char *)object + 0x138);
    unsigned short maximum = *(volatile unsigned short *)(entry + 4);
    unsigned short current = *(volatile unsigned short *)entry;
    if (current >= maximum) return false;
    {
        *result = 0;
        memset(buffer, -1, 8);
        return true;
    }
    return false;
}
