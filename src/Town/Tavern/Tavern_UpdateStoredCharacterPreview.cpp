#include <globaldefs.h>
extern "C" void *Tavern_GetStoredCharacterByIndex(void *, int);
extern "C" void CharacterStatus_RefreshChangedDisplayMode(void *, int, int);
// Original: arm9/ov003 @ 0x02161438; symbol: func_ov003_02161438; size: 0x48.
extern "C" void Tavern_UpdateStoredCharacterPreview(void *object) {
    unsigned char *base = (unsigned char *)object + 0x400;
    int index = *(short *)(base + 0x8c) - 0x15 + (signed char)base[0x9f] * 4;
    int value = -1;
    void *record = Tavern_GetStoredCharacterByIndex(object, index);
    if (record) value = ((signed char)*(unsigned char *)record << 26) >> 26;
    CharacterStatus_RefreshChangedDisplayMode(*(void **)((char *)object + 0x318), 6, value);
}
