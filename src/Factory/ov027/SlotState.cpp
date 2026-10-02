#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/Memory.h>

// Slot identifiers are one-based, in the range 1..15. The purpose of the
// payload and state values is still unknown; offsets follow their users.
struct SlotPayload {
    unsigned char bytes[22];
};

typedef void (*SlotCallback)(unsigned int, unsigned int, unsigned int);
struct SlotContext {
    unsigned char unknown0000[0x1340];
    SlotPayload payloads[15];
    unsigned char unknown148a[0x5a];
    SlotCallback callback;
    unsigned int states[15];
    unsigned char unknown1524[0x230];
    unsigned short results[15];
    SlotPayload scratch;
};

extern "C" {
extern SlotContext* data_ov027_021e33ec;
int func_ov027_021d9de8(unsigned int slot);
ARM void func_ov027_021d8c6c(unsigned int slot, unsigned int state, unsigned int detail);

ARM void func_ov027_021d8a40(SlotCallback callback) {
    int interrupts = DisableIRQInterrupts();
    data_ov027_021e33ec->callback = callback;
    SetIRQInterruptState(interrupts);
}

ARM SlotPayload* func_ov027_021d8a68(unsigned int slot) {
    int interrupts = DisableIRQInterrupts();
    if (data_ov027_021e33ec && func_ov027_021d9de8(slot)) {
        VectorizedInvertedMemcpy(&data_ov027_021e33ec->payloads[slot - 1],
                                &data_ov027_021e33ec->scratch, sizeof(SlotPayload));
        SetIRQInterruptState(interrupts);
        return &data_ov027_021e33ec->scratch;
    }
    SetIRQInterruptState(interrupts);
    return 0;
}

ARM int func_ov027_021d8aec(unsigned int slot) {
    if (data_ov027_021e33ec && func_ov027_021d9de8(slot)) {
        if (data_ov027_021e33ec->states[slot - 1] == 7) return 1;
    }
    return 0;
}

ARM int func_ov027_021d8b40(unsigned int slot, unsigned int operation) {
    // Declaration order preserves MWCC's allocation of the switch temporaries.
    unsigned int result;
    unsigned int requiredState;
    int interrupts = DisableIRQInterrupts();
    switch (operation) {
    case 0: requiredState = 10; result = 4; break;
    case 1: requiredState = 10; result = 3; break;
    case 2: requiredState = 14; result = 2; break;
    case 3: requiredState = 7; result = 5; break;
    default:
        SetIRQInterruptState(interrupts);
        return 0;
    }
    if (data_ov027_021e33ec && func_ov027_021d9de8(slot) &&
        data_ov027_021e33ec->states[slot - 1] == requiredState) {
        data_ov027_021e33ec->results[slot - 1] = result;
        SetIRQInterruptState(interrupts);
        return 1;
    }
    SetIRQInterruptState(interrupts);
    return 0;
}

ARM void func_ov027_021d8c20(unsigned int slot, unsigned int state, unsigned int detail) {
    if (func_ov027_021d9de8(slot)) data_ov027_021e33ec->states[slot - 1] = state;
    func_ov027_021d8c6c(slot, state, detail);
}

ARM void func_ov027_021d8c6c(unsigned int slot, unsigned int state, unsigned int detail) {
    if (data_ov027_021e33ec->callback) data_ov027_021e33ec->callback(slot, state, detail);
}
}
