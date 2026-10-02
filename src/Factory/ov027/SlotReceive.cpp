#include <globaldefs.h>
#include <System/Memory.h>
#include "SlotContext.h"

#pragma optimize_for_size off
// This handler retains separate slot-index calculations across basic blocks.
#pragma opt_common_subs off

struct DecodedSlotMessage {
    unsigned char operation;
    unsigned short value;
    unsigned char bytes[16];
};
struct ReceivedSlotPayload {
    unsigned int handle;
    EventSlotPayload payload;
    unsigned short identifier;
    unsigned char group;
};

extern "C" {
extern EventSlotContext* data_ov027_021e33ec;
extern unsigned int data_ov027_021dd920;
unsigned char* func_ov027_021dd6bc(void* packet, DecodedSlotMessage* message, unsigned int slot);
void func_ov027_021d8c20(unsigned int slot, unsigned int state, void* detail);
unsigned short func_ov027_021d9dd8(unsigned short first, unsigned short second);

ARM void func_ov027_021d9134(void* packet, unsigned int slot) {
    if (slot == 0 || slot > 15) return;
    DecodedSlotMessage message;
    ReceivedSlotPayload received;
    unsigned int state;
    unsigned char* payload = func_ov027_021dd6bc((unsigned char*)packet + 10, &message, slot);
    unsigned char operation = message.operation;
    EventSlotContext* context = data_ov027_021e33ec;
    state = context->states[slot - 1];
    switch (operation) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 11:
        break;
    case 7:
        if (state == 2) {
            if (!payload) return;
            VectorizedInvertedMemcpy(payload, &received, 29);
            data_ov027_021e33ec->handles[slot - 1] = received.handle;
            data_ov027_021e33ec->identifiers[slot - 1] = received.identifier;
            VectorizedInvertedMemcpy(&received.payload, &data_ov027_021e33ec->payloads[slot - 1], 22);
            EventSlotPayload* destination = &data_ov027_021e33ec->payloads[slot - 1];
            destination->header.slot = (unsigned char)slot;
            func_ov027_021d8c20(slot, 10, &received.payload);
        }
        if (state != 10) return;
        {
            unsigned char group = payload[28];
            unsigned char count = 0;
            EventGroupView* view;
            unsigned int handle;
            if (group >= 16 ||
                !(view = (EventGroupView*)((unsigned char*)data_ov027_021e33ec + group * 0x5d4))->active ||
                (handle = data_ov027_021e33ec->handles[slot - 1],
                 handle != view->descriptor->handle)) {
                data_ov027_021e33ec->results[slot - 1] = 4;
            } else {
                unsigned char index = 0;
                while (index < 16) {
                    if (view->members & (1 << index)) ++count;
                    ++index;
                }
                if (count >= ((EventGroupView*)((unsigned char*)data_ov027_021e33ec + group * 0x5d4))->descriptor->capacity) {
                    data_ov027_021e33ec->results[slot - 1] = 0;
                    func_ov027_021d8c20(slot, 11, 0);
                    return;
                }
            }
            switch (data_ov027_021e33ec->results[slot - 1]) {
            case 3:
                if (data_ov027_021e33ec->pending & (1 << slot)) return;
                ++data_ov027_021e33ec->pendingCount;
                data_ov027_021e33ec->pending |= 1 << slot;
                data_ov027_021e33ec->groups[slot - 1] = group;
                *(unsigned short*)((unsigned char*)data_ov027_021e33ec + 0x1d4e + group * 0x5d4) |= 1 << slot;
                *(unsigned short*)((unsigned char*)data_ov027_021e33ec + 0x1d50 + group * 0x5d4) |= 1 << slot;
                data_ov027_021e33ec->results[slot - 1] = 0;
                func_ov027_021d8c20(slot, 5, 0);
                return;
            case 4:
                data_ov027_021e33ec->results[slot - 1] = 0;
                func_ov027_021d8c20(slot, 4, 0);
                return;
            default: return;
            }
        }
    case 8:
        if (state == 5) {
            func_ov027_021d8c20(slot, 14, 0);
            return;
        }
        if (state != 14 || data_ov027_021e33ec->results[slot - 1] != 2) return;
        {
            unsigned char group = data_ov027_021e33ec->groups[slot - 1];
            *(unsigned short*)((unsigned char*)data_ov027_021e33ec + 0x1d4c + group * 0x5d4) |= 1 << slot;
            ((EventGroupView*)((unsigned char*)data_ov027_021e33ec + group * 0x5d4))->counter = 0;
            data_ov027_021e33ec->results[slot - 1] = 0;
            func_ov027_021d8c20(slot, 6, 0);
        }
        return;
    case 9:
        if (state != 6) return;
        {
            unsigned char group = data_ov027_021e33ec->groups[slot - 1];
            if (group == 255) return;
            unsigned short acknowledgement = func_ov027_021d9dd8(
                ((EventGroupView*)((unsigned char*)data_ov027_021e33ec + group * 0x5d4))->acknowledgement,
                message.value);
            ((EventGroupView*)((unsigned char*)data_ov027_021e33ec + group * 0x5d4))->acknowledgement = acknowledgement;
            data_ov027_021dd920 |= 1 << group;
        }
        return;
    case 10:
        if (state == 6) {
            unsigned char group = data_ov027_021e33ec->groups[slot - 1];
            if (group == 255) return;
            *(unsigned short*)((unsigned char*)data_ov027_021e33ec + 0x1d4c + group * 0x5d4) &= ~(1 << slot);
            func_ov027_021d8c20(slot, 7, 0);
            return;
        }
        if (state != 7 || data_ov027_021e33ec->results[slot - 1] != 5) return;
        data_ov027_021e33ec->results[slot - 1] = 0;
        func_ov027_021d8c20(slot, 8, 0);
        return;
    }
}
}
