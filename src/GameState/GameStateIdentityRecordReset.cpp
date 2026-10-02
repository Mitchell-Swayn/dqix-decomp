#include "GameState/GameState.h"
#include "System/Memory.h"

#if defined(usa)

typedef char GameStateIdentityRecordTimerOffsetCheck[
    offsetof(GameStateIdentityRecord, timer_) == 8 ? 1 : -1];

extern "C" void func_0200fad4(GameStateIdentityRecord* record)
{
    VectorizedMemset(record->identity_.bytes_, 0, 6);
    record->lowFlag_ = 0;
    record->upperFlags_ = 0;
    record->timer_ = 0.0f;
}

#endif
