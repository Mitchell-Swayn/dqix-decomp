#include "GameState/GameState.h"

extern "C" char* ReadGlobalValueAt02108844();

typedef char GameStateSizeCheck[sizeof(GameState) == 0x7ff4 ? 1 : -1];
typedef char GameStateUnknown5cb0OffsetCheck[
    offsetof(GameState, unknown_5cb0_) == 0x5cb0 ? 1 : -1];
typedef char GameStateUnknown5cb4OffsetCheck[
    offsetof(GameState, unknown_5cb4_) == 0x5cb4 ? 1 : -1];
typedef char GameStateUnknown5cb8OffsetCheck[
    offsetof(GameState, unknown_5cb8_) == 0x5cb8 ? 1 : -1];
typedef char GameStateUnknown5cbcOffsetCheck[
    offsetof(GameState, unknown_5cbc_) == 0x5cbc ? 1 : -1];

// Original: arm9/main @ 0x02010774; symbol: func_02010774; size: 0x28.
extern "C" void GameState_SetField5CB0AndSelectedRecordFirstByte(GameState* state, unsigned int value)
{
    state->unknown_5cb0_ = value;
    char* record = ReadGlobalValueAt02108844();
    unsigned char recordIndex = *((unsigned char*)record + 0x332);
    *((unsigned char*)record + recordIndex * 0x1c) = value;
}

// Original: arm9/main @ 0x0201079C; symbol: func_0201079c; size: 0xC.
extern "C" unsigned int GameState_ReadWordAtOffset5CB0(GameState* state)
{
    return state->unknown_5cb0_;
}

// Original: arm9/main @ 0x020107A8; symbol: func_020107a8; size: 0x28.
extern "C" void GameState_WriteField5CB4AndIndexedRecordValue(GameState* state, unsigned int value)
{
    state->unknown_5cb4_ = value;
    char* record = ReadGlobalValueAt02108844();
    unsigned char recordIndex = *((unsigned char*)record + 0x332);
    *((unsigned char*)record + recordIndex * 0x1c + 1) = value;
}

// Original: arm9/main @ 0x020107D0; symbol: func_020107d0; size: 0xC.
extern "C" unsigned int GameState_ReadUnknown5cb4(GameState* state)
{
    return state->unknown_5cb4_;
}

// Original: arm9/main @ 0x020107DC; symbol: func_020107dc; size: 0x28.
extern "C" void GameState_SetWord5CB8AndSelectedRecordByte(GameState* state, unsigned int value)
{
    state->unknown_5cb8_ = value;
    char* record = ReadGlobalValueAt02108844();
    unsigned char recordIndex = *((unsigned char*)record + 0x332);
    *((unsigned char*)record + recordIndex * 0x1c + 2) = value;
}

// Original: arm9/main @ 0x02010804; symbol: func_02010804; size: 0xC.
extern "C" unsigned int GameState_ReadUnknownCb8(GameState* state)
{
    return state->unknown_5cb8_;
}

// Original: arm9/main @ 0x02010810; symbol: func_02010810; size: 0xC.
extern "C" void GameState_SetUnknown5cbc(GameState* state, unsigned int value)
{
    state->unknown_5cbc_ = value;
}

// Original: arm9/main @ 0x0201081C; symbol: func_0201081c; size: 0xC.
extern "C" unsigned int GameState_ReadWordAtOffset5CBC(GameState* state)
{
    return state->unknown_5cbc_;
}
