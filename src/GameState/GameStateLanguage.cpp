#include "GameState/GameState.h"

#if defined(usa)

struct FirmwareUserInfo {
    unsigned char language_;
    char unknown_01_[0x54 - 1];
};

typedef char GameStateLanguageOffsetCheck[
    offsetof(GameState, language_) == 5 ? 1 : -1];

extern "C" void OS_GetOwnerInfo(FirmwareUserInfo* info);

// Original: arm9/main @ 0x0200FB08; symbol: func_0200fb08; size: 0x38.
extern "C" unsigned int GameState_ReadSupportedFirmwareLanguage(GameState* state)
{
    FirmwareUserInfo info;
    OS_GetOwnerInfo(&info);
    state->language_ = info.language_;
    if (state->language_ != 2 && state->language_ != 5)
        state->language_ = 1;
    return state->language_;
}

#endif
