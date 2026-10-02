#ifndef OV006_ITEM_SELECTION_H
#define OV006_ITEM_SELECTION_H

// Partial layout of the overlay's item selection controller. The allocator at
// 021576a0 creates nine ID/quantity arrays and nine counts. Unreconstructed
// controller subobjects retain their original space; they are not new storage.
struct ItemSelectionMenu;

struct ItemSelection {
    unsigned char unknown000[0x14];
    ItemSelectionMenu* menu;               // 014
    unsigned char unknown018[0x44 - 0x18];
    short* activeControl;                  // 044
    short** categoryIds;                   // 048
    unsigned char** categoryQuantities;     // 04c
    unsigned short* categoryCounts;         // 050
    unsigned char unknown054[0x35e - 0x54];
    short previousControl;                // 35e
    unsigned char unknown360[2];
    short categoryControl;                 // 362, category index + 0x5b
    short entryControl;                    // 364, row index + 0x64
    unsigned char unknown366[0x372 - 0x366];
    unsigned short pendingCategories[3];    // 372
    short pendingIds[3];                    // 378
    unsigned char unknown37e[0x388 - 0x37e];
    unsigned char page;                     // 388
    unsigned char pageCount;                // 389
    unsigned char unknown38a;
    unsigned char requestedQuantity;        // 38b
    unsigned char pendingQuantities[3];      // 38c
    unsigned char unknown38f[0x430 - 0x38f];
    unsigned char quantityIncreased;        // 430
    unsigned char quantityDecreased;        // 431
};

extern "C" {
short* func_ov006_0215919c(ItemSelection* self);
unsigned char* func_ov006_021591c4(ItemSelection* self);
unsigned short func_ov006_021591ec(ItemSelection* self);
int func_ov006_02159218(ItemSelection* self);
void func_ov006_02159274(ItemSelection* self, unsigned char* category,
                       short* id, unsigned char* quantity);
void func_ov006_0215951c(ItemSelection* self);
void func_ov006_02159320(ItemSelection* self);
void func_ov006_021593b0(ItemSelection* self);
int func_ov006_02159564(ItemSelection* self);
void func_ov006_02159094(ItemSelection* self);
void func_ov006_02159108(ItemSelection* self, unsigned char category,
                       short id, unsigned char quantity);
}

#endif
