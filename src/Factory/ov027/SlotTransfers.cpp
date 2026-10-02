#include <globaldefs.h>
#include <System/Memory.h>

#pragma optimize_for_size off

// A view of one transfer within the shared context; views overlap preceding storage.
struct SlotTransferGroup {
    unsigned char preceding[0x1788];
    unsigned char payload[0xe4];
    unsigned char unknown186c[0x4d4];
    void* descriptor;
    unsigned int unknown1d44;
    unsigned short counter;
    unsigned short acknowledgement;
    unsigned short mask;
    unsigned short members;
    unsigned short removed;
    unsigned char active;
    unsigned char unknown1d53[9];
};

struct SlotTransferContext {
    unsigned char unknown0000[0x14e4];
    // Entry zero overlaps the callback; transfer loops use slots 1..15.
    unsigned int states[16];
    unsigned char unknown1524;
    signed char groups[16];
    unsigned char unknown1535[0x253];
};

struct SlotTransferMessage {
    unsigned char operation;
    unsigned short value;
    unsigned short detail;
};

extern "C" {
extern SlotTransferContext* data_ov027_021e33ec;
extern unsigned int data_ov027_021dd920;
extern unsigned char data_ov027_021dd8e0;
unsigned short* func_020d49c4(void* packet, unsigned short slot);
void func_ov027_021d9134(void* packet, unsigned int slot);
void* func_ov027_021dd638(const void* message, void* context);
int func_ov027_021dab00(unsigned int operation, unsigned int slots, void* context);

ARM void func_ov027_021d9618(void* packet) {
    unsigned short group = 0;
    do {
        SlotTransferContext* context = data_ov027_021e33ec;
        SlotTransferGroup* transfer = (SlotTransferGroup*)((unsigned char*)context + group * 0x5d4);
        if (transfer->active) transfer->acknowledgement = 0;
    } while (++group < 16);
    data_ov027_021dd920 = 0;
    unsigned short slot = 1;
    do {
        unsigned short* entry = func_020d49c4(packet, slot);
        if (entry && *entry != 0xffff && *entry != 0)
            func_ov027_021d9134(entry, slot);
    } while (++slot <= 15);
}

ARM int func_ov027_021d96c4(unsigned int operation, unsigned int slots) {
    // Optional message halfwords are left untouched, as in the original helper.
    SlotTransferMessage message;
    message.operation = operation;
    func_ov027_021dd638(&message, data_ov027_021e33ec);
    return func_ov027_021dab00(6, slots, data_ov027_021e33ec);
}

ARM int func_ov027_021d9704() {
    signed char selected = -1;
    unsigned short slots = 0;
    SlotTransferMessage message;
    unsigned char counts[16];
    VectorizedMemset(counts, 0, sizeof(counts));
    SlotTransferContext* context = data_ov027_021e33ec;
    unsigned short slot = 1;
    do {
        if (context->states[slot] == 5) ++counts[context->groups[slot]];
    } while (++slot <= 15);
    unsigned char group = data_ov027_021dd8e0;
    unsigned char attempt = 0;
    do {
        group = (group + 1) % 16;
        if (((SlotTransferGroup*)((unsigned char*)context + group * 0x5d4))->active &&
            counts[group]) {
            selected = group;
            break;
        }
    } while (++attempt < 16);
    if (selected == -1) return 21;
    data_ov027_021dd8e0 = selected;
    slot = 1;
    do {
        if (context->states[slot] == 5 && selected == context->groups[slot])
            slots |= 1 << slot;
    } while (++slot <= 15);
    message.operation = 3;
    message.value = selected;
    void* destination = func_ov027_021dd638(&message, context);
    if (destination) {
        unsigned char* source = (unsigned char*)data_ov027_021e33ec + 0x1788;
        VectorizedInvertedMemcpy(source + selected * 0x5d4, destination, 0xe4);
    }
    return func_ov027_021dab00(234, slots, data_ov027_021e33ec);
}
}
