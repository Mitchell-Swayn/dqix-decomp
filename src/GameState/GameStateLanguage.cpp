#include "GameState/GameState.h"

#if defined(usa)

struct FirmwareUserInfo {
    unsigned char language_;
    char unknown_01_[0x54 - 1];
};

typedef char GameStateLanguageOffsetCheck[
    offsetof(GameState, language_) == 5 ? 1 : -1];

extern "C" void func_020c99c8(FirmwareUserInfo* info);

extern "C" unsigned int func_0200fb08(GameState* state)
{
    FirmwareUserInfo info;
    func_020c99c8(&info);
    state->language_ = info.language_;
    if (state->language_ != 2 && state->language_ != 5)
        state->language_ = 1;
    return state->language_;
}

#endif
