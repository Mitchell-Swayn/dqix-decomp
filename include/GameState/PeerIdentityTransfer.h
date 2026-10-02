#pragma once

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

// The presentation allocation is 0xecc bytes (func_ov017_021a9768). Its transfer areas
// are established by the 44-byte identity reset and 124-byte copy in overlay 8.
struct PeerIdentityPresentation {
    char unknown_000_[0x1f4];
    void* unknown_1f4_;
    void* unknown_1f8_;
    void* unknown_1fc_;
    SafeAllocator allocators_[6];
    char unknown_278_[0xdf0 - 0x278];
    GameStateStoredIdentity storedIdentity_;
    unsigned char presentationData_[0x7c];
    unsigned char transferFlags_;
    char unknown_e99_[0xecc - 0xe99];
};

// This is only the recovered prefix. No complete manager extent is claimed.
struct PeerIdentityManagerPrefix {
    unsigned char kind_;
    unsigned char finished_;
    char unknown_02_[6];
    unsigned char state_;
    unsigned char unknown_09_;
    char unknown_0a_[2];
    SafeAllocator allocator_;
    PeerIdentityPresentation* presentation_;
    signed char objectIndex_;
    unsigned char identityPayloadOffset_;
    unsigned char presentationDataOffset_;
    char unknown_27_;
    GameStateStoredIdentity storedIdentity_;
    void* unknown_54_;
};
