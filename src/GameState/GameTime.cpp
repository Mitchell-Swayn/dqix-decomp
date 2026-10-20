#include "GameState/GameState.h"

// not correct, they're separate but we need the full TU before we can do this properly
// Original data: arm9/main @ 0x20f33b4; symbol: data_020f33b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern float GameStateSetDayTimer_UnknownRoleZeroInitializedStorage[6];

// Original: arm9/main @ 0x02010150; symbol: _ZN9GameState18CalculateDeltaTimeEy; size: 0xB8.
void GameState::CalculateDeltaTime(uint64_t microseconds)
{
    if (microseconds > 50000)
        microseconds = 50000;

    numTicks_ = currentNumTicks_;
    currentNumTicks_ = 0;
    if (numTicks_ > 3)
        numTicks_ = 3;

    trueDeltaTimeMilliseconds_ = microseconds / 1000;
    effectiveDeltaTimeMilliseconds_ = trueDeltaTimeMilliseconds_ * (gameSpeed_ / 4096.0f);
    animationDeltaTime_ = 4096.0f * (effectiveDeltaTimeMilliseconds_ / 17.0f);
}

// Original: arm9/main @ 0x02010208; symbol: _ZNK9GameState21GetEffectiveDeltaTimeEv; size: 0x8.
unsigned int GameState::GetEffectiveDeltaTime() const { return effectiveDeltaTimeMilliseconds_; }
// Original: arm9/main @ 0x02010210; symbol: _ZNK9GameState16GetTrueDeltaTimeEv; size: 0x8.
unsigned int GameState::GetTrueDeltaTime() const { return trueDeltaTimeMilliseconds_; }
// Original: arm9/main @ 0x02010218; symbol: _ZNK9GameState21GetAnimationDeltaTimeEv; size: 0x8.
fix32_t GameState::GetAnimationDeltaTime() const { return animationDeltaTime_; }
// Original: arm9/main @ 0x02010220; symbol: _ZNK9GameState12GetTickCountEv; size: 0x8.
unsigned int GameState::GetTickCount() const { return numTicks_; }
// Original: arm9/main @ 0x02010228; symbol: _ZN9GameState12SetGameSpeedEi; size: 0xC.
void GameState::SetGameSpeed(fix32_t speed) { gameSpeed_ = speed; }
// Original: arm9/main @ 0x02010234; symbol: _ZNK9GameState12GetGameSpeedEv; size: 0xC.
fix32_t GameState::GetGameSpeed() const { return gameSpeed_; }

// Original: arm9/main @ 0x02010240; symbol: _ZN9GameState15AdvanceDayTimerEv; size: 0x40.
void GameState::AdvanceDayTimer()
{
    if (dayTimerRunning_ == 0)
        return;

    SetDayTimer(dayTimer_ + (numTicks_ * daySpeed_));
}

// Original: arm9/main @ 0x02010280; symbol: _ZNK9GameState11GetDayTimerEv; size: 0x8.
float GameState::GetDayTimer() const { return dayTimer_; }

// Original: arm9/main @ 0x02010288; symbol: _ZN9GameState11SetDayTimerEf; size: 0xCC.
void GameState::SetDayTimer(float to)
{
    if (to >= dayLength_)
    {
        int numCycles = to / dayLength_;
        to -= numCycles * dayLength_;
    }

    dayTimer_ = to;
    if (dayTimer_ >= dayLength_)
        dayTimer_ -= dayLength_;

#if defined(usa) // this is diabolical
    if (dayTimer_ >= GameStateSetDayTimer_UnknownRoleZeroInitializedStorage[2])
#elif defined(jpn)
    if (dayTimer_ >= GameStateSetDayTimer_UnknownRoleZeroInitializedStorage[1])
#endif
        timeOfDay_ = TimeOfDay_Evening;
    else if (dayTimer_ >= GameStateSetDayTimer_UnknownRoleZeroInitializedStorage[3])
        timeOfDay_ = TimeOfDay_Day;
    else if (dayTimer_ >= GameStateSetDayTimer_UnknownRoleZeroInitializedStorage[4])
        timeOfDay_ = TimeOfDay_Morning;
    else
        timeOfDay_ = TimeOfDay_Night;
}

// Original: arm9/main @ 0x02010354; symbol: _ZN9GameState18SetDayTimerRunningEi; size: 0x8.
void GameState::SetDayTimerRunning(CBool to) { dayTimerRunning_ = to; }
// Original: arm9/main @ 0x0201035C; symbol: _ZNK9GameState12GetTimeOfDayEv; size: 0x8.
TimeOfDay GameState::GetTimeOfDay() const { return timeOfDay_; }

// Original: arm9/main @ 0x02010364; symbol: _ZN9GameState12SetTimeOfDayE9TimeOfDay; size: 0x50.
void GameState::SetTimeOfDay(TimeOfDay to)
{
    if ((int)to < 4)
    {
        timeOfDay_ = to;
        float thresholds[4] = {
            GameStateSetDayTimer_UnknownRoleZeroInitializedStorage[5],
            GameStateSetDayTimer_UnknownRoleZeroInitializedStorage[4],
            GameStateSetDayTimer_UnknownRoleZeroInitializedStorage[3],
#if defined(usa)
            GameStateSetDayTimer_UnknownRoleZeroInitializedStorage[2]
#elif defined(jpn)
            GameStateSetDayTimer_UnknownRoleZeroInitializedStorage[1]
#endif
        };
        SetDayTimer(thresholds[to]);
    }
}

// Original: arm9/main @ 0x020103B4; symbol: _ZNK9GameState21IsMorningDayOrEveningEv; size: 0x14.
bool GameState::IsMorningDayOrEvening() const { return timeOfDay_ != TimeOfDay_Night; }