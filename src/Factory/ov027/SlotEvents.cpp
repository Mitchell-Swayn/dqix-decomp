#include <globaldefs.h>
#include <System/Memory.h>

#pragma optimize_for_size off

#include "SlotContext.h"

extern "C" {
void func_ov027_021dd5f4(unsigned int slot);
void func_ov027_021d9618(void* packet);
void func_ov027_021d9bdc();
void func_ov027_021dad14(void* update, void* payloads, unsigned int members, unsigned int removed);
unsigned int func_ov027_021dd024();
unsigned int func_ov027_021dd038();
unsigned int func_ov027_021dd04c();
void func_ov027_021dae40(unsigned int, unsigned int, unsigned int);
void func_ov027_021d9e04(unsigned int, unsigned int);
void func_020ca458(int value, void* destination, unsigned int size);

ARM void func_ov027_021d8c94(int event, SlotEvent* detail) {
    switch (event) {
    case 17:
        break;
    case 21:
        func_ov027_021d8c20(0, 1, (unsigned int)detail);
        break;
    case 0:
        if (detail->slot != 0 && detail->slot < 16)
            func_ov027_021d8c20(detail->slot, 2, (unsigned int)detail);
        break;
    case 1:
        if (detail->slot == 0 || detail->slot >= 16) break;
        data_ov027_021e33ec->identifiers[detail->slot - 1] = 0;
        VectorizedMemset(&data_ov027_021e33ec->handles[detail->slot - 1], 0, 4);
        VectorizedMemset(&data_ov027_021e33ec->payloads[detail->slot - 1], 0, 22);
        func_ov027_021dd5f4(detail->slot);
        data_ov027_021e33ec->results[detail->slot - 1] = 0;
        {
            unsigned int slot = detail->slot;
            unsigned int index = slot - 1;
            EventSlotContext* context = data_ov027_021e33ec;
            signed char group = context->groups[index];
            if (group != -1) {
                unsigned int mask;
                mask = ~(1 << slot);
                EventGroupView* view = (EventGroupView*)((unsigned char*)context + (unsigned char)group * 0x5d4);
                view->members &= mask;
                ((EventGroupView*)((unsigned char*)data_ov027_021e33ec + (unsigned char)group * 0x5d4))->removed |= 1 << slot;
                data_ov027_021e33ec->groups[index] = -1;
                ((EventGroupView*)((unsigned char*)data_ov027_021e33ec + (unsigned char)group * 0x5d4))->mask &= mask;
            }
        }
        if (data_ov027_021e33ec->pending & (1 << detail->slot)) {
            --data_ov027_021e33ec->pendingCount;
            data_ov027_021e33ec->pending &= ~(1 << detail->slot);
        }
        if (data_ov027_021e33ec->states[detail->slot - 1] == 8)
            func_ov027_021d8c20(detail->slot, 9, 0);
        func_ov027_021d8c20(detail->slot, 3, (unsigned int)detail);
        data_ov027_021e33ec->states[detail->slot - 1] = 0;
        break;
    case 3:
        func_ov027_021d9618(detail);
        break;
    case 25:
        func_ov027_021d9bdc();
        break;
    case 28:
        {
            unsigned char group = 0;
            do {
                unsigned int offset = group * 0x5d4;
                EventSlotContext* context = data_ov027_021e33ec;
                EventGroupView* view = (EventGroupView*)((unsigned char*)context + offset);
                if (view->active && view->removed) {
                    func_ov027_021dad14((unsigned char*)context + 0x186c + offset, context->payloads, view->members, view->removed);
                    ((EventGroupView*)((unsigned char*)data_ov027_021e33ec + offset))->removed = 0;
                }
            } while (++group < 16);
            unsigned int first = func_ov027_021dd024();
            unsigned int second = func_ov027_021dd038();
            unsigned int third = func_ov027_021dd04c();
            func_ov027_021dae40(first, second, third);
        }
        break;
    case 255:
        switch (detail->reason) {
        case 1: case 4: case 5: case 6: case 8: case 9:
            func_ov027_021d9e04(0, 9);
            break;
        case 0: case 2: case 3: case 7: case 10: case 11:
        case 12: case 13: case 14: case 15:
        default:
            func_ov027_021d9e04(0, 8);
            break;
        }
        break;
    case 256:
        switch (detail->result) {
        case 0: case 7: case 8: case 13: case 14: case 15:
        case 17: case 18: case 21: case 25: case 29:
            func_ov027_021d9e04(0, 9);
            break;
        case 1: case 2: case 3: case 4: case 5: case 6:
        case 9: case 10: case 11: case 12: case 16: case 19:
        case 20: case 22: case 23: case 24: case 26: case 27: case 28:
        default:
            func_ov027_021d9e04(0, 8);
            break;
        }
        break;
    }
    if (event == 17) {
        EventSlotCallback callback = data_ov027_021e33ec->callback;
        func_020ca458(0, data_ov027_021e33ec, 0x7d00);
        data_ov027_021e33ec = 0;
        if (callback) callback(0, 12, 0);
    }
}
}
