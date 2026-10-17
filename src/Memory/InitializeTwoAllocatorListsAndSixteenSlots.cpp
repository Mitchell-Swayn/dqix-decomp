#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct Slot {
    SignedAllocatorHeader header;
    unsigned char unknown_24[8];
    unsigned char unknown_2c;
    unsigned char unknown_2d[0xf];
    unsigned char index;
    unsigned char unknown_3d[7];
};

struct Channel {
    SignedAllocatorList listA;
    SignedAllocatorList listB;
    int unknown_18;
    int unknown_1c;
    unsigned char unknown_20;
    unsigned char unknown_21[3];
};

extern "C" {
extern SignedAllocatorList data_0210f3cc;
extern SignedAllocatorList data_0210f3d8;
extern Slot data_0210f3e4[16];
extern Channel data_0210f824[32];
}

// Original: arm9/main @ 0x020BC23C; symbol: func_020bc23c; size: 0xB4.
extern "C" ARM void InitializeTwoAllocatorListsAndSixteenSlots() {
    data_0210f3d8.Initialize(0x14);
    data_0210f3cc.Initialize(0x14);
    int i;
    Slot* slot = data_0210f3e4;
    i = 0;
    do {
        slot->unknown_2c = 0;
        slot->index = i;
        data_0210f3cc.InsertAtEnd(&slot->header);
        slot++;
    } while (++i < 16);
    Channel* channel = data_0210f824;
    int j = 0;
    do {
        channel->listA.Initialize(0xc);
        channel->listB.Initialize(0);
        channel->unknown_20 = 0x7f;
        channel->unknown_18 = 1;
        channel->unknown_1c = 0;
        channel++;
    } while (++j < 32);
}
