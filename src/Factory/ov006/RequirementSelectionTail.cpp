#include "SelectionEntry.h"
using namespace Ov006Selection;

extern "C" void* memset(void*, int, unsigned int);
extern "C" Record* func_02071d60(void*, int);
extern "C" int func_ov006_02153a78(State* self, int multiplier) {
    if (!self->record) return 0;
    if (self->record->ids[0] > 0 && self->record->quantity0) {
        if (self->indices[0] < 0) return 0;
        if (self->categories[0] < 0) return 0;
        if ((int)self->record->quantity0 * multiplier > self->categoryQuantities[self->categories[0]][self->indices[0]]) return 0;
    }
    if (self->record->ids[1] > 0 && self->record->quantity1) {
        if (self->indices[1] < 0) return 0;
        if (self->categories[1] < 0) return 0;
        if ((int)self->record->quantity1 * multiplier > self->categoryQuantities[self->categories[1]][self->indices[1]]) return 0;
    }
    if (self->record->ids[2] > 0 && self->record->quantity2) {
        if (self->indices[2] < 0) return 0;
        if (self->categories[2] < 0) return 0;
        if ((int)self->record->quantity2 * multiplier > self->categoryQuantities[self->categories[2]][self->indices[2]]) return 0;
    }
    return 1;
}
extern "C" void func_ov006_02153b9c(State* self, int id, unsigned char* output) {
    memset(output, 0, 3);
    Record* record = func_02071d60(self->records, id);
    if (!record) return;
    for (int category = 0; category < 9; ++category) {
        short* ids = self->categoryIds[category];
        unsigned char* quantities = self->categoryQuantities[category];
        short count = self->categoryCounts[category];
        for (short index = 0; index < count; ++index) {
            int itemId = ids[index];
            if (itemId > 0) {
                if (itemId == record->ids[0]) output[0] = quantities[index];
                else if (itemId == record->ids[1]) output[1] = quantities[index];
                else if (itemId == record->ids[2]) output[2] = quantities[index];
            }
        }
    }
}
extern "C" void func_ov006_02153c60(State* self, Entry* entries, unsigned short count) {
    self->entries = entries;
    self->entryCount = count;
}
extern "C" Entry* func_ov006_02153c6c(State* self, int id) {
    if (id < 0) return 0;
    unsigned short count = self->entryCount;
    for (unsigned short index = 0; index < count; ++index) {
        Entry* entries = self->entries;
        int itemId = entries[index].id;
        if (itemId == id) return &entries[index];
    }
    return 0;
}
