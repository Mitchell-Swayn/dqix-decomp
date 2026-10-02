// Explicit identity checks and aggregate copies are embedded in the release.
#pragma always_inline on
#include "GameState/GameState.h"
#include "System/Memory.h"

#if defined(usa)

typedef char StoredIdentitySizeCheck[sizeof(GameStateStoredIdentity) == 0x2c ? 1 : -1];
typedef char StoredIdentityTicksOffsetCheck[
    offsetof(GameStateStoredIdentity, partialTicks_) == 0x11 ? 1 : -1];
typedef char PeerIdentitySizeCheck[sizeof(GameStatePeerIdentity) == 10 ? 1 : -1];
typedef char StoredIdentitiesOffsetCheck[
    offsetof(GameState, storedIdentities_) == 0x7200 ? 1 : -1];
typedef char PeerIdentitiesOffsetCheck[
    offsetof(GameState, peerIdentities_) == 0x74c0 ? 1 : -1];
typedef char IdentityUpdateStateSizeCheck[sizeof(GameState) == 0x7ff4 ? 1 : -1];

extern "C" void func_0200fad4(GameStateIdentityRecord* record);
extern "C" bool func_02011fb4(const NativeIdentity* source, NativeIdentity identity);

extern "C" void func_02011b68(GameState* state)
{
    NativeIdentity pending[4];
    unsigned char objectIndices[4] = {0};
    NativeIdentity identity;
    int objectCount;
    CBool newRecord;
    float delta;
    memcpy(objectIndices, state->unknownByteBuffer_571d_,
           state->unknownByteBufferLength_5721_);
    objectCount = (signed char)state->unknownByteBufferLength_5721_;
    int pendingCount = 0;
    memset(pending, 0, sizeof(pending));
    GameStatePeerIdentity* peer = state->peerIdentities_;
    for (int i = 0; i < 3; ++i)
        state->identityRecords_[i].lowFlag_ = 0;

    for (int i = 0; i < 3; ++i, ++peer) {
        newRecord = 0;
        VectorizedMemset(identity.bytes_, newRecord, 6);
        for (int j = 0; j < objectCount; ++j) {
            if (peer->objectIndex_ == objectIndices[j]) {
                identity = peer->identity_;
                if (peer->objectIndex_ >= 0 &&
                    peer->objectIndex_ != state->protagonistObjectIndex_) {
                    newRecord = 1;
                    for (int k = 0; k < 3; ++k) {
                        if (func_02011fb4(&state->identityRecords_[k].identity_, identity)) {
                            state->identityRecords_[k].lowFlag_ = 1;
                            newRecord = 0;
                            break;
                        }
                    }
                }
            }
        }
        if (newRecord) {
            pending[pendingCount] = identity;
            pendingCount = (signed char)(pendingCount + 1);
        }
    }
    for (int i = 0; i < pendingCount; ++i) {
        if (!pending[i].IsZero()) {
            for (int j = 0; j < 3; ++j) {
                if (!state->identityRecords_[j].lowFlag_) {
                    GameStateIdentityRecord* record = &state->identityRecords_[j];
                    func_0200fad4(record);
                    state->identityRecords_[j].lowFlag_ = 1;
                    record->identity_ = pending[i];
                    break;
                }
            }
        }
    }
    // The release advances one 60-unit interval at most per call, even when
    // the timer has accumulated multiple intervals.
    delta = state->numTicks_ * state->daySpeed_;
    for (int i = 0; i < 3; ++i) {
        if (state->identityRecords_[i].lowFlag_) {
            state->identityRecords_[i].timer_ += delta;
            if (state->identityRecords_[i].timer_ >= 60.0f) {
                GameStateStoredIdentity* stored = state->storedIdentities_;
                for (int j = 0; j < 16; ++j, ++stored) {
                    if (stored->active_ &&
                        func_02011fb4(&stored->identity_, state->identityRecords_[i].identity_)) {
                        if (++stored->partialTicks_ >= 60) {
                            if (stored->counter_ >= 9999)
                                stored->partialTicks_ = 59;
                            else {
                                ++stored->counter_;
                                stored->partialTicks_ = 0;
                            }
                        }
                        break;
                    }
                }
                state->identityRecords_[i].timer_ -= 60.0f;
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (!state->identityRecords_[i].lowFlag_)
            func_0200fad4(&state->identityRecords_[i]);
    }
}

#endif
