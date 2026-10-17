#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadSupportedFirmwareLanguage(void*);
extern "C" const char* data_ov023_021fff08;
// Original: arm9/ov023 @ 0x021F5788; symbol: func_ov023_021f5788; size: 0x3C.
extern "C" int func_ov023_021f5788(const void* p) {
    int language = _ZNK6Script9Parameter5ToIntEv(p);
    void* gameState = _ZN9GameState11GetInstanceEv();
    if (language == GameState_ReadSupportedFirmwareLanguage(gameState)) {
        *(const char**)((char*)&data_ov023_021fff08 + 0x10) = _ZNK6Script9Parameter8ToStringEv((const char*)p + 8);
    }
    return 1;
}
