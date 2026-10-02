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
extern "C" void func_020113a8(GameState* state, unsigned int group,
                              unsigned int index)
{
    unsigned int bit = (group - 1) * 5 + index;
    unsigned int byte = bit / 8;
    unsigned char mask = 1 << (bit - byte * 8);
    state->unknownBitFlags_5cd0_[byte] |= mask;
}

extern "C" void func_020113e0(GameState* state)
{
    for (int i = 0; i < 10; ++i)
        state->unknownBitFlags_5cd0_[i] = 0xff;
}

extern "C" void func_02011408(GameState* state)
{
    for (int i = 0; i < 10; ++i)
        state->unknownBitFlags_5cd0_[i] = 0;
}

extern "C" bool func_02011430(GameState* state, unsigned int group,
                              unsigned int index)
{
    unsigned int bit = (group - 1) * 5 + index;
    unsigned int byte = bit / 8;
    unsigned char mask = 1 << (bit - byte * 8);
    return (state->unknownBitFlags_5cd0_[byte] & mask) != 0;
}

extern "C" void func_02011468(GameState* state, unsigned int length,
                              const void* source)
{
    memcpy(state->unknownByteBuffer_5718_, source, length);
    state->unknownByteBufferLength_571c_ = length;
}

extern "C" unsigned int func_02011494(GameState* state, void* destination)
{
    memcpy(destination, state->unknownByteBuffer_5718_,
           state->unknownByteBufferLength_571c_);
    return state->unknownByteBufferLength_571c_;
}

extern "C" void func_020114c0(GameState* state, unsigned int length,
                              const void* source)
{
    memcpy(state->unknownByteBuffer_571d_, source, length);
    state->unknownByteBufferLength_5721_ = length;
}

extern "C" unsigned int func_020114ec(GameState* state, void* destination)
{
    memcpy(destination, state->unknownByteBuffer_571d_,
           state->unknownByteBufferLength_5721_);
    return state->unknownByteBufferLength_5721_;
}

extern "C" int func_02011518(GameState* state, unsigned int index)
{
    if (index < state->unknownByteBufferLength_5721_)
        return state->unknownByteBuffer_571d_[index];
    return -1;
}

extern "C" unsigned int func_02011538(GameState* state)
{
    return state->unknownByteBufferLength_5721_;
}
