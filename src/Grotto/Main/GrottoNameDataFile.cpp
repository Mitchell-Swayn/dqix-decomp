#include "GameState/GameState.h"

// USA: func_02011644
// JPN: func_020113b4
// Original: arm9/main @ 0x02011644; symbol: _ZN9GameState26GetTreasureMapLanguageDataEv; size: 0xC.
unsigned char* GameState::GetTreasureMapLanguageData()
{
    return treasureMapLanguageData_;
}

// USA: func_02011650
// JPN: func_020113b4
// Original: arm9/main @ 0x02011650; symbol: _ZN9GameState29SetTreasureMapLanguageDataPtrEPh; size: 0xC.
void GameState::SetTreasureMapLanguageDataPtr(unsigned char* to)
{
    treasureMapLanguageData_ = to;
}