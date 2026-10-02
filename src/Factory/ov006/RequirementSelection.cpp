extern "C" void* memset(void*, int, unsigned int);

// Partial lookup-record layout inferred from these accesses. Field names describe
// observed use; the record's broader purpose remains unresolved.
struct RequirementRecord {
    short unknown0[2];
    short ids[3];
    unsigned short quantity0 : 4;
    unsigned short quantity1 : 4;
    unsigned short quantity2 : 4;
    unsigned short unknownQuantity : 4;
    unsigned int unknownC;
    unsigned int unknown10 : 22;
    unsigned int selected : 1;
    unsigned int unknownFlags : 9;
};
struct RequirementSelection {
    void* records;
    short** categoryIds;
    unsigned char** categoryQuantities;
    unsigned short* categoryCounts;
    RequirementRecord* record;
    short indices[3];
    signed char categories[3];
    unsigned int unknown20;
    unsigned short unknown24;
};
struct SelectionEntry {
    short id;
    unsigned short flag0 : 1;
    unsigned short flag1 : 1;
    unsigned short otherFlags : 14;
};
extern "C" RequirementRecord* func_02071d60(void*, int);
extern "C" void func_ov006_021536e0(RequirementSelection* self) {
    self->records = 0;
    self->categoryIds = 0;
    self->categoryQuantities = 0;
    self->categoryCounts = 0;
    self->record = 0;
    memset(self->indices, -1, 6);
    memset(self->categories, -1, 3);
    self->unknown20 = 0;
    self->unknown24 = 0;
}
extern "C" void func_ov006_02153730(RequirementSelection* self) {
    func_ov006_021536e0(self);
}
extern "C" void func_ov006_0215373c(RequirementSelection* self, void* records) {
    self->records = records;
}
extern "C" void func_ov006_02153744(RequirementSelection*, void* records, SelectionEntry* entries, int count) {
    for (int i = 0; i < count; ++i, ++entries) {
        RequirementRecord* record = func_02071d60(records, entries->id);
        if (record)
            record->selected = entries->flag0 || entries->flag1;
    }
}
extern "C" void func_ov006_021537c8(RequirementSelection* self, short** ids,
                                  unsigned char** quantities, unsigned short* counts) {
    self->categoryIds = ids;
    self->categoryQuantities = quantities;
    self->categoryCounts = counts;
}
extern "C" int func_ov006_021537d0(RequirementSelection* self, int id) {
    // Each requirement searches all nine categories. A later category can replace
    // an earlier match; only the inner search stops. Inactive slots retain state.
    if (!self->categoryCounts) return 0;
    self->record = func_02071d60(self->records, id);
    if (!self->record) return 0;
    if (self->record->ids[0] > 0 && self->record->quantity0) {
        self->indices[0] = -1;
        self->categories[0] = -1;
        for (signed char category = 0; category < 9; ++category) {
            short* ids = self->categoryIds[category];
            unsigned short count = self->categoryCounts[category];
            for (unsigned short index = 0; index < count; ++index) {
                if (self->record->ids[0] == ids[index]) {
                    self->indices[0] = index;
                    self->categories[0] = category;
                    break;
                }
            }
        }
        if (self->indices[0] < 0) return 0;
        if ((int)self->record->quantity0 >
            self->categoryQuantities[self->categories[0]][self->indices[0]]) return 0;
    }
    if (self->record->ids[1] > 0 && self->record->quantity1) {
        self->indices[1] = -1;
        self->categories[1] = -1;
        for (signed char category = 0; category < 9; ++category) {
            short* ids = self->categoryIds[category];
            unsigned short count = self->categoryCounts[category];
            for (unsigned short index = 0; index < count; ++index) {
                if (self->record->ids[1] == ids[index]) {
                    self->indices[1] = index;
                    self->categories[1] = category;
                    break;
                }
            }
        }
        if (self->indices[1] < 0) return 0;
        if ((int)self->record->quantity1 >
            self->categoryQuantities[self->categories[1]][self->indices[1]]) return 0;
    }
    if (self->record->ids[2] > 0 && self->record->quantity2) {
        self->indices[2] = -1;
        self->categories[2] = -1;
        for (signed char category = 0; category < 9; ++category) {
            short* ids = self->categoryIds[category];
            unsigned short count = self->categoryCounts[category];
            for (unsigned short index = 0; index < count; ++index) {
                if (self->record->ids[2] == ids[index]) {
                    self->indices[2] = index;
                    self->categories[2] = category;
                    break;
                }
            }
        }
        if (self->indices[2] < 0) return 0;
        if ((int)self->record->quantity2 >
            self->categoryQuantities[self->categories[2]][self->indices[2]]) return 0;
    }
    return 1;
}
