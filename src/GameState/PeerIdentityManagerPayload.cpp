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

extern "C" void func_ov017_021a9714(PeerIdentityManagerPrefix* manager);

extern "C" void func_ov017_021a9998(PeerIdentityManagerPrefix* manager)
{
    if (manager->presentation_)
        func_ov008_02189404(manager->presentation_);
}

extern "C" void func_ov017_021a99b0(PeerIdentityManagerPrefix* manager)
{
    if (manager->presentation_)
        func_ov008_0218946c(manager->presentation_);
}

extern "C" void func_ov017_021a99c8(PeerIdentityManagerPrefix* manager)
{
    manager->finished_ = 1;
    func_ov017_021a9714(manager);
}

extern "C" void func_ov017_021a99dc(PeerIdentityManagerPrefix* manager,
                                     const unsigned char* payload, unsigned int type,
                                     unsigned int length, unsigned char complete)
{
    if (!manager->presentation_)
        return;
    // The release trusts lengths and byte offsets for all three transfer areas.
    if (type == 0) {
        memcpy(manager->presentation_->storedIdentity_.payload_ +
                   manager->identityPayloadOffset_, payload, length);
        manager->identityPayloadOffset_ += length;
    } else if (type == 2) {
        memcpy(&manager->presentation_->storedIdentity_, payload, length);
        manager->presentation_->transferFlags_ |= 4;
    } else {
        manager->presentation_->transferFlags_ |= 1;
        memcpy(manager->presentation_->presentationData_ +
                   manager->presentationDataOffset_, payload, length);
        manager->presentationDataOffset_ += length;
    }
    if (complete)
        manager->presentation_->transferFlags_ |= 2;
}

#endif
