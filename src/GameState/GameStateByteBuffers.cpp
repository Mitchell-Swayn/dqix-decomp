#include "GameState/GameState.h"

typedef char GameStateByteBuffer5718OffsetCheck[
    offsetof(GameState, unknownByteBuffer_5718_) == 0x5718 ? 1 : -1];
typedef char GameStateByteBuffer571dOffsetCheck[
    offsetof(GameState, unknownByteBuffer_571d_) == 0x571d ? 1 : -1];
typedef char GameStateBitFlags5cd0OffsetCheck[
    offsetof(GameState, unknownBitFlags_5cd0_) == 0x5cd0 ? 1 : -1];
typedef char GameStateByteBufferSizeCheck[sizeof(GameState) == 0x7ff4 ? 1 : -1];

// These helpers address a ten-byte bitset in groups of five bits. The caller's
// first group number is one-based; the semantic meaning of the bits is unknown.
// Original: arm9/main @ 0x020113A8; symbol: func_020113a8; size: 0x38.
extern "C" void GameState_SetGroupedFiveBitFlag(GameState* state, unsigned int group,
                              unsigned int index)
{
    unsigned int bit = (group - 1) * 5 + index;
    unsigned int byte = bit / 8;
    unsigned char mask = 1 << (bit - byte * 8);
    state->unknownBitFlags_5cd0_[byte] |= mask;
}

// Original: arm9/main @ 0x020113E0; symbol: func_020113e0; size: 0x28.
extern "C" void GameState_SetAllGroupedFiveBitFlags(GameState* state)
{
    for (int i = 0; i < 10; ++i)
        state->unknownBitFlags_5cd0_[i] = 0xff;
}

// Original: arm9/main @ 0x02011408; symbol: func_02011408; size: 0x28.
extern "C" void GameState_ClearTenBitFlagWords(GameState* state)
{
    for (int i = 0; i < 10; ++i)
        state->unknownBitFlags_5cd0_[i] = 0;
}

// Original: arm9/main @ 0x02011430; symbol: func_02011430; size: 0x38.
extern "C" bool GameState_TestGroupedFiveBitFlag(GameState* state, unsigned int group,
                              unsigned int index)
{
    unsigned int bit = (group - 1) * 5 + index;
    unsigned int byte = bit / 8;
    unsigned char mask = 1 << (bit - byte * 8);
    return (state->unknownBitFlags_5cd0_[byte] & mask) != 0;
}

// Original: arm9/main @ 0x02011468; symbol: func_02011468; size: 0x2C.
extern "C" void GameState_StoreProtagonistPartySlotList(GameState* state, unsigned int length,
                              const void* source)
{
    memcpy(state->unknownByteBuffer_5718_, source, length);
    state->unknownByteBufferLength_571c_ = length;
}

// Original: arm9/main @ 0x02011494; symbol: func_02011494; size: 0x2C.
extern "C" unsigned int GameState_CopyProtagonistPartySlotList(GameState* state, void* destination)
{
    memcpy(destination, state->unknownByteBuffer_5718_,
           state->unknownByteBufferLength_571c_);
    return state->unknownByteBufferLength_571c_;
}

// Original: arm9/main @ 0x020114C0; symbol: func_020114c0; size: 0x2C.
extern "C" void GameState_StoreActivePartySlotList(GameState* state, unsigned int length,
                              const void* source)
{
    memcpy(state->unknownByteBuffer_571d_, source, length);
    state->unknownByteBufferLength_5721_ = length;
}

// Original: arm9/main @ 0x020114EC; symbol: func_020114ec; size: 0x2C.
extern "C" unsigned int GameState_CopyActivePartySlotList(GameState* state, void* destination)
{
    memcpy(destination, state->unknownByteBuffer_571d_,
           state->unknownByteBufferLength_5721_);
    return state->unknownByteBufferLength_5721_;
}

// Original: arm9/main @ 0x02011518; symbol: func_02011518; size: 0x20.
extern "C" int GameState_GetActivePartySlotOrInvalid(GameState* state, unsigned int index)
{
    if (index < state->unknownByteBufferLength_5721_)
        return state->unknownByteBuffer_571d_[index];
    return -1;
}

// Original: arm9/main @ 0x02011538; symbol: func_02011538; size: 0xC.
extern "C" unsigned int GameState_GetActivePartySlotCount(GameState* state)
{
    return state->unknownByteBufferLength_5721_;
}
