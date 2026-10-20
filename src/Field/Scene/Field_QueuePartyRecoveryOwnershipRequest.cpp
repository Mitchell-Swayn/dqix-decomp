#include <globaldefs.h>
ARM
extern "C" void Field_ClearPartyRecoveryRequest(unsigned char *p);
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void *NetworkOwnership_GetRegistry(void);
extern "C" void NetworkOwnership_QueueRequest(unsigned char *p, unsigned char v);
// Original: arm9/ov017 @ 0x0218D7B0; symbol: func_ov017_0218d7b0; size: 0x4C.
extern "C" void Field_QueuePartyRecoveryOwnershipRequest(unsigned char *base, const unsigned char *source) {
    if (source == 0) {
        return;
    }
    Field_ClearPartyRecoveryRequest(base + 0x4356);
    memcpy(base + 0x4356, source, 6);
    base[0x435B] = 1;
    NetworkOwnership_QueueRequest((unsigned char *)NetworkOwnership_GetRegistry(), 1);
}
