#include <globaldefs.h>
#include <System/Matrix.h>
ARM
#pragma optimization_level 4
#pragma opt_propagation off

struct State;
struct ZoneState2754;
struct EntryBits {
    unsigned limit : 7;
    unsigned cost : 25;
};
struct PaletteIndexTable {
    unsigned char values[9];
};
struct OfferRecord {
    unsigned unused;
    void* payload;
    unsigned category : 4;
    unsigned subtype : 5;
    unsigned rest : 23;
};
struct RecordWidget {
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void SetStyle(unsigned);
    virtual void Slot55();
    virtual void SetValue(unsigned);
};

extern "C" {
void* Menu_FindInventoryGridByKey(void *self, unsigned index);
int Menu_GetInventoryRecordSourceByKey(...);
void* Menu_GetInventorySlotOnCurrentPage(void* self, unsigned column);
void* Menu_FindInventoryTextEntryByKey(State* state, unsigned value);
void *Menu_FindInventoryValueEntryByKey(void *self, unsigned key);
void *Menu_FindInventorySpriteByKey(void *state, unsigned int key);
void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754* state, int key);
int Menu_WriteGridEntry(char* p, int v, unsigned x, unsigned y);
void Menu_SetSpriteCellIndex(void* object, unsigned short value);
void Menu_RefreshSelectedOfferDetails(void* self);
// Original data: arm9/ov004 @ 0x0216fb28; symbol: MenuRefreshSixOfferRows_UnknownRoleInitializedBytes.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000103050204060708000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern PaletteIndexTable MenuRefreshSixOfferRows_UnknownRoleInitializedBytes;
// Original data: arm9/ov004 @ 0x21707d8; symbol: MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern unsigned char* MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov004 @ 0x0216fb34; symbol: MenuRefreshSixOfferRows_UnknownRoleInitializedBytes_Variant2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0040ffff0000000000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern Vector3i MenuRefreshSixOfferRows_UnknownRoleInitializedBytes_Variant2;
}

#define B(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define S(p, o) (*(short*)((char*)(p) + (o)))

// Original: arm9/ov004 @ 0x02158FEC; symbol: func_ov004_02158fec; size: 0x398.
// Refreshes six purchase-offer rows: item text, quantity, cost, sprite cell, and
// hidden empty slots, then restores the grid origin from shared storage.
extern "C" int Menu_RefreshSixOfferRows(void* self)
{
    unsigned keyA = 0x12c;
    unsigned keyC = 0x138;
    unsigned keyB = keyA + 6;
    unsigned keyD = keyC + 6;
    unsigned keyE = 0x144;
    char* grid = (char*)Menu_FindInventoryGridByKey(self, 0x5b);

    if (S(grid, 0x5e) <= 1) {
        S(grid, 0x5c) = 0;
        S(grid, 0x5e) = 1;
    }

    void* source = (void*)Menu_GetInventoryRecordSourceByKey(self, 5);
    if (!source)
        return 0;

    PaletteIndexTable table = MenuRefreshSixOfferRows_UnknownRoleInitializedBytes;
    unsigned i = 0;
    goto compare;
    for (;;) {
        char* slot = (char*)Menu_GetInventorySlotOnCurrentPage(self, i);
        if (slot) {
            unsigned color = 0xf;
            if (((EntryBits*)(slot + 4))->limit == 0)
                color = 3;
            if (S(slot, 0) > 0) {
                RecordWidget* textA = (RecordWidget*)Menu_FindInventoryTextEntryByKey((State*)self, keyA);
                if (textA) {
                    OfferRecord* record = (OfferRecord*)ZoneState2754_FindPrimaryRecordByKey(
                        (ZoneState2754*)source, S(slot, 0));
                    if (record) {
                        *(void**)((char*)textA + 0x20) = record->payload;
                        void* sprite = Menu_FindInventorySpriteByKey(self, i + 0x14a);
                        if (record->category == 0) {
                            if (sprite)
                                Menu_SetSpriteCellIndex(
                                    sprite, (unsigned short)(record->subtype + 0x26));
                        } else if (sprite) {
                            Menu_SetSpriteCellIndex(
                                sprite, (unsigned short)(table.values[record->category] + 9));
                        }
                    }
                    textA->SetStyle(color);
                }
                RecordWidget* textB = (RecordWidget*)Menu_FindInventoryTextEntryByKey((State*)self, keyB);
                if (textB)
                    textB->SetStyle(color);
                RecordWidget* textC = (RecordWidget*)Menu_FindInventoryTextEntryByKey((State*)self, keyC);
                if (textC)
                    textC->SetStyle(color);
                RecordWidget* valueA = (RecordWidget*)Menu_FindInventoryValueEntryByKey(self, keyD);
                if (valueA) {
                    valueA->SetValue(((EntryBits*)(slot + 4))->limit);
                    valueA->SetStyle(color);
                }
                RecordWidget* valueB = (RecordWidget*)Menu_FindInventoryValueEntryByKey(self, keyE);
                if (valueB) {
                    valueB->SetValue(((EntryBits*)(slot + 4))->cost);
                    valueB->SetStyle(color);
                }
            } else {
                RecordWidget* textA = (RecordWidget*)Menu_FindInventoryTextEntryByKey((State*)self, keyA);
                if (textA)
                    B(textA, 0xc) = B(textA, 0xc) | 8;
                RecordWidget* textB = (RecordWidget*)Menu_FindInventoryTextEntryByKey((State*)self, keyB);
                if (textB)
                    B(textB, 0xc) = B(textB, 0xc) | 8;
                RecordWidget* textC = (RecordWidget*)Menu_FindInventoryTextEntryByKey((State*)self, keyC);
                if (textC)
                    B(textC, 0xc) = B(textC, 0xc) | 8;
                RecordWidget* valueA = (RecordWidget*)Menu_FindInventoryValueEntryByKey(self, keyD);
                if (valueA)
                    B(valueA, 0xc) = B(valueA, 0xc) | 8;
                RecordWidget* valueB = (RecordWidget*)Menu_FindInventoryValueEntryByKey(self, keyE);
                if (valueB)
                    B(valueB, 0xc) = B(valueB, 0xc) | 8;
                Menu_WriteGridEntry(grid, 0, i, 0);
                void* sprite = Menu_FindInventorySpriteByKey(self, i + 0x14a);
                if (sprite)
                    B(sprite, 0xc) = B(sprite, 0xc) | 8;
            }
        }
        keyA++;
        keyB++;
        keyC++;
        keyD++;
        keyE++;
        i = (i + 1) & 0xff;
    compare:
        if (i < 6)
            continue;
        break;
    }

    Menu_RefreshSelectedOfferDetails(self);
    if (MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2][0x31] == 0) {
        Vector3i position = MenuRefreshSixOfferRows_UnknownRoleInitializedBytes_Variant2;
        *(Vector3i*)(grid + 0x2c) = position;
        MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2][0x31] = 0;
    }
    return 0;
}
