#include <globaldefs.h>

extern "C" int Network_FindWirelessSlotByMemberId(void* state, int value);
extern "C" int Network_FindPreviousWirelessSlotByMemberId(void* state, int value);

// Original: arm9/main @ 0x0202C5BC; symbol: func_0202c5bc; size: 0x44.
extern "C" void Network_MarkMemberDisconnected(void* state, int value)
{
    int bit = Network_FindWirelessSlotByMemberId(state, value);
    if (bit < 0) {
        bit = Network_FindPreviousWirelessSlotByMemberId(state, value);
        if (bit < 0) {
            return;
        }
    }

    volatile unsigned char* flags = static_cast<unsigned char*>(state) + 0x100e;
    unsigned char current = *flags;
    unsigned int bitMask = 1;
    *flags = static_cast<unsigned char>(current | (bitMask << bit));
}
