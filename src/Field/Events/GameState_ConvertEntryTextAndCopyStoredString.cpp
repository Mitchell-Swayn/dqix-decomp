#include <globaldefs.h>
ARM
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void Text_ConvertAndStoreBoundedText(char*, void*, int);
extern "C" char* strcpy(char*, const char*);
// Original: arm9/ov017 @ 0x021C4618; symbol: func_ov017_021c4618; size: 0x4C.
extern "C" void GameState_ConvertEntryTextAndCopyStoredString(void* unused, const unsigned char* source, void* gameState, char* output) {
    unsigned int index = source[4];
    void* object = GameState_GetObjectWithFlag100(gameState, index);
    if (!object) return;
    Text_ConvertAndStoreBoundedText((char*)object, (void*)(source + 5), 1);
    strcpy(output + 0x435c + index * 0x30, *(const char**)((char*)object + 0x134));
}
