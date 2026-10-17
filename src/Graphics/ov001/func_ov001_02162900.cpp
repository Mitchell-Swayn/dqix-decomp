#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" void VectorizedMemset(void*, int, unsigned int);
extern "C" void LoadToMainBG3CharacterData(const void*, unsigned int, unsigned int);
extern "C" void LoadToMainBG3ScreenData(const void*, unsigned int, unsigned int);
extern "C" void LoadToSubBG3CharacterData(const void*, unsigned int, unsigned int);
extern "C" void LoadToSubBG3ScreenData(const void*, unsigned int, unsigned int);
// Original: arm9/ov001 @ 0x02162900; symbol: func_ov001_02162900; size: 0x7C.
extern "C" int func_ov001_02162900(void* parameter) {
    int sub = ReadScriptParameterAsInteger(parameter);
    char character[0x20];
    char screen[0x600];
    VectorizedMemset(character, 0, 0x20);
    VectorizedMemset(screen, 0, 0x600);
    if (sub == 0) {
        LoadToMainBG3CharacterData(character, 0, 0x20);
        LoadToMainBG3ScreenData(screen, 0, 0x600);
    } else {
        LoadToSubBG3CharacterData(character, 0, 0x20);
        LoadToSubBG3ScreenData(screen, 0, 0x600);
    }
    return 1;
}
