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

extern "C" void func_02011818(GameState* state,
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
        VectorizedInvertedMemcpy(input->text_07_,
                                  state->grottoInfo_.metadataTransfer_.text_73_, 10);
    if (input->text_13_[0] == 0)
        state->grottoInfo_.metadataTransfer_.text_7d_[0] = 0;
    else
        VectorizedInvertedMemcpy(input->text_13_,
                                  state->grottoInfo_.metadataTransfer_.text_7d_, 10);
    if (input->value_24_ != 0)
        state->grottoInfo_.metadataTransfer_.unknown_10_ = input->value_24_;
    state->grottoInfo_.metadataTransfer_.unknown_0c_ = input->value_20_;
    state->grottoInfo_.metadataTransfer_.unknown_08_ = -1;
}

extern "C" void func_020118fc(GameState* state)
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

extern "C" unsigned int func_02011930(GameState* state,
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
            VectorizedInvertedMemcpy(state->grottoInfo_.metadataTransfer_.text_73_, text73, 10);
            state->grottoInfo_.metadataTransfer_.text_73_[0] = 0;
        }
        if (text7d != NULL) {
            VectorizedInvertedMemcpy(state->grottoInfo_.metadataTransfer_.text_7d_, text7d, 10);
            state->grottoInfo_.metadataTransfer_.text_7d_[0] = 0;
        }
    }
    return state->grottoInfo_.metadataTransfer_.available_;
}

extern "C" unsigned int func_020119cc(GameState* state)
{
    return state->grottoInfo_.metadataTransfer_.unknown_01_;
}

extern "C" void func_020119d8(GameState* state)
{
    state->grottoInfo_.metadataTransfer_.metadataAvailable_ = 1;
}

extern "C" void func_020119e8(GameState* state)
{
    state->grottoInfo_.metadataTransfer_.metadataAvailable_ = 0;
}

extern "C" unsigned int func_020119f8(GameState* state, TreasureMapMetadata* metadata)
{
    if (metadata != NULL)
        VectorizedInvertedMemcpy(&state->grottoInfo_.metadataTransfer_.metadata_, metadata, 0x1c);
    return state->grottoInfo_.metadataTransfer_.metadataAvailable_;
}

extern "C" void func_02011a24(GameState* state, const TreasureMapMetadata* metadata)
{
    VectorizedInvertedMemcpy(metadata, &state->grottoInfo_.metadataTransfer_.metadata_, 0x1c);
}

extern "C" void func_02011a40(GameState* state)
{
    TreasureMapMetadata metadata;
    metadata.SetMapType(TreasureMapType_Invalid);
    VectorizedInvertedMemcpy(&metadata, &state->grottoInfo_.metadataTransfer_.metadata_, 0x1c);
}

#endif
