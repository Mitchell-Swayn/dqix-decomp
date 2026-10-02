#ifndef OV006_ITEM_SELECTION_H
#define OV006_ITEM_SELECTION_H

// Partial layout of the overlay's item selection controller. The allocator at
// 021576a0 creates nine ID/quantity arrays and nine counts. Unreconstructed
// controller subobjects retain their original space; they are not new storage.
struct ItemSelection {
    unsigned char unknown000[0x48];
    short** categoryIds;                   // 048
    unsigned char** categoryQuantities;     // 04c
    unsigned short* categoryCounts;         // 050
    unsigned char unknown054[0x362 - 0x54];
    short categoryControl;                 // 362, category index + 0x5b
    short entryControl;                    // 364, row index + 0x64
    unsigned char unknown366[0x388 - 0x366];
    unsigned char page;                     // 388
    unsigned char pageCount;                // 389
};

extern "C" {
short* func_ov006_0215919c(ItemSelection* self);
unsigned char* func_ov006_021591c4(ItemSelection* self);
unsigned short func_ov006_021591ec(ItemSelection* self);
int func_ov006_02159218(ItemSelection* self);
void func_ov006_02159274(ItemSelection* self, unsigned char* category,
                       short* id, unsigned char* quantity);
void func_ov006_0215951c(ItemSelection* self);
}

#endif
