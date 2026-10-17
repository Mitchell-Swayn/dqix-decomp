#include "GameState/GameState.h"
#include "System/Memory.h"

#if defined(usa)

struct GrottoMetadataTransferInput
{
    unsigned char kind_;
    unsigned char value_01_;
    unsigned char value_02_;
    char unknown_03_;
    unsigned short value_04_;
    unsigned char value_06_;
    char text_07_[10];
    char unknown_11_[2];
    char text_13_[10];
    char unknown_1d_[3];
    unsigned int value_20_;
    unsigned char value_24_;
    char unknown_25_;
    unsigned short value_26_;
};

typedef char GrottoMetadataTransferInputSizeCheck[
    sizeof(GrottoMetadataTransferInput) == 0x28 ? 1 : -1];
typedef char GrottoMetadataTransferStateSizeCheck[
    sizeof(GrottoMetadataTransferState) == 0x88 ? 1 : -1];
typedef char GrottoMetadataTransferStateOffsetCheck[
    offsetof(GrottoStruct, metadataTransfer_) == 0x88 ? 1 : -1];
typedef char GrottoMetadataTransferText73OffsetCheck[
    offsetof(GrottoMetadataTransferState, text_73_) == 0x73 ? 1 : -1];
typedef char GrottoMetadataTransferText7dOffsetCheck[
    offsetof(GrottoMetadataTransferState, text_7d_) == 0x7d ? 1 : -1];
typedef char GrottoMetadataTransferGameStateSizeCheck[
    sizeof(GameState) == 0x7ff4 ? 1 : -1];

// Original: arm9/main @ 0x02011818; symbol: func_02011818; size: 0xE4.
extern "C" void GameState_PopulateGrottoMetadataTransferDescriptor(GameState* state,
                              const GrottoMetadataTransferInput* input)
{
    state->grottoInfo_.metadataTransfer_.available_ = 1;
    state->grottoInfo_.metadataTransfer_.unknown_01_ = input->value_06_;
    state->grottoInfo_.metadataTransfer_.descriptor_.kind_ = input->kind_;
    if (input->kind_ == 1) {
        state->grottoInfo_.metadataTransfer_.descriptor_.value_01_ = input->value_01_;
        state->grottoInfo_.metadataTransfer_.descriptor_.value_02_ = input->value_04_;
    } else {
        state->grottoInfo_.metadataTransfer_.descriptor_.value_01_ = input->value_01_;
        state->grottoInfo_.metadataTransfer_.descriptor_.value_02_ = input->value_02_;
        if (input->value_26_ != 0)
            state->grottoInfo_.metadataTransfer_.unknown_12_ = input->value_26_;
    }
    if (input->text_07_[0] == 0)
        state->grottoInfo_.metadataTransfer_.text_73_[0] = 0;
    else
        MI_CpuCopy8(input->text_07_,
                                  state->grottoInfo_.metadataTransfer_.text_73_, 10);
    if (input->text_13_[0] == 0)
        state->grottoInfo_.metadataTransfer_.text_7d_[0] = 0;
    else
        MI_CpuCopy8(input->text_13_,
                                  state->grottoInfo_.metadataTransfer_.text_7d_, 10);
    if (input->value_24_ != 0)
        state->grottoInfo_.metadataTransfer_.unknown_10_ = input->value_24_;
    state->grottoInfo_.metadataTransfer_.unknown_0c_ = input->value_20_;
    state->grottoInfo_.metadataTransfer_.unknown_08_ = -1;
}

// Original: arm9/main @ 0x020118FC; symbol: func_020118fc; size: 0x34.
extern "C" void GameState_ResetGrottoMetadataTransfer(GameState* state)
{
    state->grottoInfo_.metadataTransfer_.available_ = 0;
    state->grottoInfo_.metadataTransfer_.unknown_01_ = 0;
    state->grottoInfo_.metadataTransfer_.descriptor_.kind_ = 0;
    state->grottoInfo_.metadataTransfer_.descriptor_.value_01_ = 0;
    state->grottoInfo_.metadataTransfer_.descriptor_.value_02_ = 0;
    state->grottoInfo_.metadataTransfer_.unknown_0c_ = -1;
    state->grottoInfo_.metadataTransfer_.unknown_10_ = 0;
    state->grottoInfo_.metadataTransfer_.unknown_12_ = 0;
}

// Original: arm9/main @ 0x02011930; symbol: func_02011930; size: 0x9C.
extern "C" unsigned int GameState_TransferAvailableGrottoDescriptorAndTexts(GameState* state,
                                      GrottoMetadataDescriptor* descriptor,
                                      char* text73, char* text7d)
{
    if (state->grottoInfo_.metadataTransfer_.available_ != 0) {
        if (descriptor != NULL) {
            descriptor->kind_ = state->grottoInfo_.metadataTransfer_.descriptor_.kind_;
            descriptor->value_01_ = state->grottoInfo_.metadataTransfer_.descriptor_.value_01_;
            descriptor->value_02_ = state->grottoInfo_.metadataTransfer_.descriptor_.value_02_;
        }
        if (text73 != NULL) {
            MI_CpuCopy8(state->grottoInfo_.metadataTransfer_.text_73_, text73, 10);
            state->grottoInfo_.metadataTransfer_.text_73_[0] = 0;
        }
        if (text7d != NULL) {
            MI_CpuCopy8(state->grottoInfo_.metadataTransfer_.text_7d_, text7d, 10);
            state->grottoInfo_.metadataTransfer_.text_7d_[0] = 0;
        }
    }
    return state->grottoInfo_.metadataTransfer_.available_;
}

// Original: arm9/main @ 0x020119CC; symbol: func_020119cc; size: 0xC.
extern "C" unsigned int ReadGrottoInfoMetadataTransferUnknown(GameState* state)
{
    return state->grottoInfo_.metadataTransfer_.unknown_01_;
}

// Original: arm9/main @ 0x020119D8; symbol: func_020119d8; size: 0x10.
extern "C" void GameState_MarkGrottoMetadataAvailable(GameState* state)
{
    state->grottoInfo_.metadataTransfer_.metadataAvailable_ = 1;
}

// Original: arm9/main @ 0x020119E8; symbol: func_020119e8; size: 0x10.
extern "C" void GameState_ClearGrottoMetadataAvailable(GameState* state)
{
    state->grottoInfo_.metadataTransfer_.metadataAvailable_ = 0;
}

// Original: arm9/main @ 0x020119F8; symbol: func_020119f8; size: 0x2C.
extern "C" unsigned int GameState_CopyAvailableGrottoTransferMetadata(GameState* state, TreasureMapMetadata* metadata)
{
    if (metadata != NULL)
        MI_CpuCopy8(&state->grottoInfo_.metadataTransfer_.metadata_, metadata, 0x1c);
    return state->grottoInfo_.metadataTransfer_.metadataAvailable_;
}

// Original: arm9/main @ 0x02011A24; symbol: func_02011a24; size: 0x1C.
extern "C" void GameState_CopyTreasureMapMetadata(GameState* state, const TreasureMapMetadata* metadata)
{
    MI_CpuCopy8(metadata, &state->grottoInfo_.metadataTransfer_.metadata_, 0x1c);
}

// Original: arm9/main @ 0x02011A40; symbol: func_02011a40; size: 0x34.
extern "C" void GameState_SetTransferredTreasureMapTypeInvalid(GameState* state)
{
    // The release sets only the type bits, then copies this stack record.
    // Its other bits and bytes are uninitialized; no stronger caller contract
    // has been established.
    TreasureMapMetadata metadata;
    metadata.SetMapType(TreasureMapType_Invalid);
    MI_CpuCopy8(&metadata, &state->grottoInfo_.metadataTransfer_.metadata_, 0x1c);
}

// Original: arm9/main @ 0x02011A74; symbol: func_02011a74; size: 0x2C.
extern "C" void GameState_CopyGrottoTransferText(GameState* state, unsigned int index, const char* text)
{
    if (text == NULL)
        return;
    char* destination = state->grottoInfo_.metadataTransfer_.text_32_;
    if (destination == NULL)
        return;
    if (index > 3)
        return;
    strcpy(destination, text);
}

// Original: arm9/main @ 0x02011AA0; symbol: func_02011aa0; size: 0x18.
extern "C" char* GameState_GetGrottoMetadataTextForValidIndex(GameState* state, unsigned int index)
{
    char* result = NULL;
    if (index <= 3)
        result = state->grottoInfo_.metadataTransfer_.text_32_;
    return result;
}

// Original: arm9/main @ 0x02011AB8; symbol: func_02011ab8; size: 0x1C.
extern "C" void GameState_ClearGrottoMetadataText32(GameState* state)
{
    VectorizedMemset(state->grottoInfo_.metadataTransfer_.text_32_, 0, 64);
}

// Original: arm9/main @ 0x02011AD4; symbol: func_02011ad4; size: 0x1C.
extern "C" void GameState_ClearGrottoTransferText(GameState* state)
{
    VectorizedMemset(state->grottoInfo_.metadataTransfer_.text_32_, 0, 64);
}

#endif
