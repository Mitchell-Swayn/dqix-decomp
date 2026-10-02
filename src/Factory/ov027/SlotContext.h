#pragma once
#include <globaldefs.h>

union EventSlotPayload {
    unsigned char bytes[22];
    struct { unsigned char group : 4; unsigned char slot : 4; } header;
};
typedef void (*EventSlotCallback)(unsigned int, unsigned int, unsigned int);
struct EventSlotContext {
    unsigned char unknown0000[0x1340];
    EventSlotPayload payloads[15];
    unsigned short identifiers[15];
    unsigned int handles[15];
    EventSlotCallback callback;
    unsigned int states[15];
    unsigned char unknown1524[2];
    signed char groups[15];
    unsigned char pendingCount;
    unsigned short pending;
    unsigned char unknown1538[0x21c];
    unsigned short results[15];
    EventSlotPayload scratch;
};
struct EventGroupDescriptor {
    unsigned char unknown0000[0x14];
    unsigned int handle;
    unsigned char capacity;
};
// This is an overlapping view at context + group * 0x5d4, not a storage array.
struct EventGroupView {
    unsigned char unknown0000[0x186c];
    unsigned char update[0x4d4];
    EventGroupDescriptor* descriptor;
    unsigned int unknown1d44;
    unsigned short counter;
    unsigned short acknowledgement;
    unsigned short mask;
    unsigned short members;
    unsigned short removed;
    unsigned char active;
};
struct SlotEvent {
    unsigned short result;
    unsigned short reason;
    unsigned char unknown0004[12];
    unsigned short slot;
};


// The detail word is an opaque 32-bit value. Event handlers pass pointer bits;
// state helpers may pass scalar values. Convert pointers explicitly at callers.
extern "C" {
extern EventSlotContext* data_ov027_021e33ec;
ARM void func_ov027_021d8c20(unsigned int slot, unsigned int state, unsigned int detail);
}
