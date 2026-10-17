#include "GameState/GameState.h"
// Three10-byte candidates begin atGameState+0x74c0; signedindex follows6identitybytes.
struct SelectedIdentityCandidate { NativeIdentity identity; signed char index; unsigned char unknown7[3]; };
// Sixteen44-byte records begin atGameState+0x7200; counter flags at0x12.
struct IdentityCounterRecord {
    NativeIdentity identity;
    unsigned char unknown6[11];
    unsigned char subcounter;
    unsigned short counter:14;
    unsigned short enabled:1;
    unsigned short unknown15:1;
    unsigned char unknown14[24];
};
typedef char SelectedIdentityCandidateSizeCheck[sizeof(SelectedIdentityCandidate)==10?1:-1];
typedef char IdentityCounterRecordSizeCheck[sizeof(IdentityCounterRecord)==44?1:-1];
extern "C" {
void __clear(void*, unsigned);
void VectorizedMemset(void*, int, unsigned);
void GameStateIdentityRecord_ClearIdentityFlagsAndTimer(GameStateIdentityRecord*);
bool NativeIdentity_CompareSixBytes(const NativeIdentity*, NativeIdentity);
}
// Original: arm9/main @ 0x02011B68; symbol: func_02011b68; size: 0x44C.
// Reconciles selected native identities and accumulates their persistent counters.
extern "C" void GameState_RefreshSelectedIdentityRecordsAndTimers(GameState* state)
{
    unsigned char selected[4];
    __clear(selected,4);
    memcpy(selected,state->unknownByteBuffer_571d_,state->unknownByteBufferLength_5721_);
    signed char selectedCount=(signed char)state->unknownByteBufferLength_5721_;
    signed char pendingCount=0;
    NativeIdentity pending[4];
    memset(pending,0,sizeof(pending));
    SelectedIdentityCandidate* candidate=(SelectedIdentityCandidate*)((char*)state+0x74c0);
    for(int i=0;i<3;i++) state->identityRecords_[i].lowFlag_=0;
    for(int i=0;i<3;i++,candidate++) {
        int append=0;
        NativeIdentity identity;
        VectorizedMemset(&identity,append,6);
        for(int j=0;j<selectedCount;j++) {
            if(candidate->index==selected[j]) {
                identity=candidate->identity;
                if(candidate->index>=0 && candidate->index!=state->protagonistObjectIndex_) {
                    append=1;
                    for(int k=0;k<3;k++) {
                        if(NativeIdentity_CompareSixBytes(&state->identityRecords_[k].identity_,identity)) {
                            state->identityRecords_[k].lowFlag_=1;
                            append=0;
                            break;
                        }
                    }
                }
            }
        }
        if(append) { pending[pendingCount]=identity; pendingCount++; }
    }
    for(int i=0;i<pendingCount;i++) {
        // Assign the zero-test result on exit to preserve the original register lifetime.
        bool allZero;
        for(int k=0;k<6;k++) { if(pending[i].bytes_[k]!=0) { allZero=false; goto identity_checked; } }
        allZero=true;
identity_checked:
        if(!allZero) {
            for(int j=0;j<3;j++) {
                if(!state->identityRecords_[j].lowFlag_) {
                    GameStateIdentityRecord_ClearIdentityFlagsAndTimer(&state->identityRecords_[j]);
                    state->identityRecords_[j].lowFlag_=1;
                    state->identityRecords_[j].identity_=pending[i];
                    break;
                }
            }
        }
    }
    float elapsed=(float)state->numTicks_*state->daySpeed_;
    for(int i=0;i<3;i++) {
        if(state->identityRecords_[i].lowFlag_) {
            state->identityRecords_[i].timer_+=elapsed;
            if(state->identityRecords_[i].timer_>=60.0f) {
                IdentityCounterRecord* counter=(IdentityCounterRecord*)((char*)state+0x7200);
                for(int j=0;j<16;j++,counter++) {
                    if(counter->enabled && NativeIdentity_CompareSixBytes(&counter->identity,state->identityRecords_[i].identity_)) {
                        if(++counter->subcounter>=60) {
                            if(counter->counter>=9999) counter->subcounter=59;
                            else { counter->counter++; counter->subcounter=0; }
                        }
                        break;
                    }
                }
                state->identityRecords_[i].timer_-=60.0f;
            }
        }
    }
    for(int i=0;i<3;i++) if(!state->identityRecords_[i].lowFlag_) GameStateIdentityRecord_ClearIdentityFlagsAndTimer(&state->identityRecords_[i]);
}
