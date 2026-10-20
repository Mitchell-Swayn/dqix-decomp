// Original: arm9/ov023:021e9370; Resolves a character from the signed selector parameter and writes its equipment index and two indexed stat values into nested outputs.
#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Script_ReadParameterAsInteger(void* parameter);
extern "C" void* Script_ResolveCharacterFromSignedSelector(int selector);
extern "C" void Script_WriteIntegerReferenceOutput(void* output, int value);
extern "C" int Script_ReadCharacterSelectedClassProgress(void* parameter) {
    (void)_ZN9GameState11GetInstanceEv();
    void* character = Script_ResolveCharacterFromSignedSelector(Script_ReadParameterAsInteger(parameter));
    if (!character) return 0;
    Script_WriteIntegerReferenceOutput((char*)parameter + 8, (int)*(unsigned*)(*(unsigned char**)((char*)character + 0x150) + 0x950));
    unsigned char* stats = *(unsigned char**)((char*)character + 0x150);
    unsigned char* second = stats + (*(unsigned*)((char*)stats + 0x950)) * 2 + 0x100;
    Script_WriteIntegerReferenceOutput((char*)parameter + 0x10, *(unsigned short*)(second + 0x6c));
    stats = *(unsigned char**)((char*)character + 0x150);
    unsigned char* third = stats + (*(unsigned*)((char*)stats + 0x950)) * 4;
    Script_WriteIntegerReferenceOutput((char*)parameter + 0x18, *(unsigned*)(third + 0x138));
    return 1;
}
