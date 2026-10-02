#include "GameState/PeerIdentityTransfer.h"
#include "System/Memory.h"

#if defined(usa)

typedef char PeerPresentationSizeCheck[sizeof(PeerIdentityPresentation) == 0xecc ? 1 : -1];
typedef char PeerPresentationIdentityOffsetCheck[
    offsetof(PeerIdentityPresentation, storedIdentity_) == 0xdf0 ? 1 : -1];
typedef char PeerPresentationDataOffsetCheck[
    offsetof(PeerIdentityPresentation, presentationData_) == 0xe1c ? 1 : -1];
typedef char PeerPresentationFlagsOffsetCheck[
    offsetof(PeerIdentityPresentation, transferFlags_) == 0xe98 ? 1 : -1];
typedef char PeerManagerAllocatorOffsetCheck[
    offsetof(PeerIdentityManagerPrefix, allocator_) == 0xc ? 1 : -1];
typedef char PeerManagerPresentationOffsetCheck[
    offsetof(PeerIdentityManagerPrefix, presentation_) == 0x20 ? 1 : -1];
typedef char PeerManagerIdentityOffsetCheck[
    offsetof(PeerIdentityManagerPrefix, storedIdentity_) == 0x28 ? 1 : -1];

extern "C" void func_0204693c(PeerIdentityManagerPrefix* manager);
extern "C" void func_0203b4e8(void* object, int flags);
extern "C" char data_02114e20[];
extern "C" void func_02012da4(const char* label, void* allocation);
extern "C" void func_ov008_02189404(PeerIdentityPresentation* presentation);
extern "C" void func_ov008_0218946c(PeerIdentityPresentation* presentation);

extern "C" void func_ov017_021a967c(PeerIdentityManagerPrefix* manager, int objectIndex)
{
    func_0204693c(manager);
    manager->kind_ = 0x3a;
    manager->allocator_.ResetAllocatorPointer();
    manager->state_ = 0;
    manager->presentation_ = 0;
    manager->objectIndex_ = objectIndex;
    manager->unknown_09_ = 0;
    manager->identityPayloadOffset_ = 0;
    manager->presentationDataOffset_ = 0;
    VectorizedMemset(manager->storedIdentity_.identity_.bytes_, 0, 6);
    memset(manager->storedIdentity_.unknown_06_, 0, 11);
    manager->storedIdentity_.counter_ = 0;
    manager->storedIdentity_.partialTicks_ = 0;
    manager->storedIdentity_.active_ = 0;
    VectorizedMemset(manager->storedIdentity_.payload_, 0, 24);
    manager->unknown_54_ = 0;
}

extern "C" void func_ov017_021a9714(PeerIdentityManagerPrefix* manager)
{
    SignedAllocatorHeader* allocation = manager->allocator_.GetSignedAllocator();
    if (allocation) {
        manager->allocator_.Destroy();
        func_02012da4(data_02114e20, allocation);
    }
    manager->allocator_.ResetAllocatorPointer();
    manager->state_ = 0;
    manager->presentation_ = 0;
    func_0203b4e8(func_ov017_0218b5b0(), 0xc0);
}

#endif
