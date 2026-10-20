#include <globaldefs.h>
ARM

extern "C" void *NetworkOwnership_GetRegistry();
extern "C" unsigned char NetworkOwnership_ClassifyLocalRequest(void *object, unsigned id);
extern "C" void NetworkOwnership_ClearLocalEntry(void *p, int id);

// Original: arm9/ov002 @ 0x0215B7D0; symbol: func_ov002_0215b7d0; size: 0x44.
extern "C" int PartyMenu_PollActionOwnershipRequest(void) {
    void *object = NetworkOwnership_GetRegistry();
    unsigned char state = NetworkOwnership_ClassifyLocalRequest(object, 1);
    if (state == 1) return 1;
    if ((unsigned int)state - 3 > 2) return 0;
    NetworkOwnership_ClearLocalEntry(object, 1);
    return -1;
}
