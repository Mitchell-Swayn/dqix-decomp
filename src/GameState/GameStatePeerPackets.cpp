#pragma always_inline on
#include "GameState/PeerIdentityTransfer.h"

#if defined(usa)

// This callback's fourth argument exposes a manager pointer at 0x3b84.
// The enclosing context's other fields and full extent are still unknown.
struct PeerPacketContextPrefix {
    char unknown_0000_[0x3b84];
    PeerIdentityManagerPrefix* manager_;
};

struct PeerIdentityPacket {
    unsigned char unknown_00_[4];
    unsigned char payload_[14];
    unsigned char target_ : 2;
    unsigned char selector_ : 2;
    unsigned char unknown_12_ : 4;
    unsigned char type_ : 2;
    unsigned char length_ : 4;
    unsigned char complete_ : 1;
    unsigned char identityTransfer_ : 1;
};

typedef char PeerPacketSizeCheck[sizeof(PeerIdentityPacket) == 20 ? 1 : -1];
typedef char PeerPacketPayloadOffsetCheck[
    offsetof(PeerIdentityPacket, payload_) == 4 ? 1 : -1];
typedef char PeerPacketContextManagerOffsetCheck[
    offsetof(PeerPacketContextPrefix, manager_) == 0x3b84 ? 1 : -1];
typedef char StoredIdentityPayloadOffsetCheck[
    offsetof(GameStateStoredIdentity, payload_) == 0x14 ? 1 : -1];
typedef char PeerTransferIndexOffsetCheck[
    offsetof(GameStatePeerIdentity, storedIdentityIndex_) == 9 ? 1 : -1];

extern "C" int func_0202c1a4(void* connection);
extern "C" void func_ov017_021a99dc(PeerIdentityManagerPrefix* manager, const unsigned char* payload,
                                     unsigned int type, unsigned int length,
                                     unsigned char complete);

extern "C" void func_ov017_021d15b0(int objectIndex, const PeerIdentityPacket* packet,
                                     GameState* state, PeerPacketContextPrefix* context,
                                     void* connection)
{
    PeerIdentityManagerPrefix* manager = context->manager_;
    int target = func_0202c1a4(connection);
    if (!packet->identityTransfer_) {
        if (target == packet->target_)
            func_ov017_021a99dc(manager, packet->payload_, packet->type_,
                               packet->length_, packet->complete_);
    } else if (packet->type_ == 2) {
        if (packet->selector_ == 1) {
            GameStatePeerIdentity* peer = state->peerIdentities_;
            for (int i = 0; i < 3; ++i, ++peer) {
                if (peer->objectIndex_ == objectIndex)
                    break;
                if (peer->objectIndex_ < 0) {
                    // The release trusts the packet length; no bound is added.
                    memcpy(&peer->identity_, packet->payload_, packet->length_);
                    peer->objectIndex_ = objectIndex;
                    break;
                }
            }
        }
    } else if (packet->type_ == 0) {
        if (packet->selector_ == 0 && target != packet->target_)
            return;
        GameStatePeerIdentity* peer = state->peerIdentities_;
        for (int i = 0; i < 3; ++i, ++peer) {
            if (peer->objectIndex_ == objectIndex) {
                if (peer->storedIdentityIndex_ < 0) {
                    GameStateStoredIdentity* stored = state->storedIdentities_;
                    int j;
                    for (j = 0; j < 16; ++j, ++stored) {
                        if (stored->active_ && stored->identity_.Equals(peer->identity_)) {
                            peer->storedIdentityIndex_ = j;
                            peer->transferActive_ = 1;
                            break;
                        }
                    }
                    if (j == 16)
                        break;
                }
                GameStateStoredIdentity* stored =
                    &state->storedIdentities_[peer->storedIdentityIndex_];
                // As in the release, the transfer offset and packet length are
                // trusted; the handler does not enforce the payload extent.
                memcpy(stored->payload_ + peer->transferOffset_, packet->payload_,
                       packet->length_);
                peer->transferOffset_ += packet->length_;
                if (packet->complete_) {
                    peer->transferActive_ = 0;
                    peer->transferOffset_ = 0;
                    peer->storedIdentityIndex_ = -1;
                }
                break;
            }
        }
    }
}

#endif
