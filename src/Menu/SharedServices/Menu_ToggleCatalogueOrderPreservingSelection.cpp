#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off

struct State;
struct Table;
struct Grid {
    char padding[0x20];
    unsigned short* entries;
    unsigned short rows, columns;
};
struct CatalogueRecord {
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3(); virtual void V4();
    virtual void V5(); virtual void V6(); virtual void V7(); virtual void V8(); virtual void V9();
    virtual void V10(); virtual void V11(); virtual void V12(); virtual void V13(); virtual void V14();
    virtual void V15(); virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23(); virtual void V24();
    virtual void V25(); virtual void V26(); virtual void V27(); virtual void V28(); virtual void V29();
    virtual void V30(); virtual void V31(); virtual void V32(); virtual void V33(); virtual void V34();
    virtual void V35(); virtual void V36(); virtual void V37(); virtual void V38(); virtual void V39();
    virtual void V40(); virtual void V41(); virtual void V42(); virtual void V43(); virtual void V44();
    virtual void V45(); virtual void V46(); virtual void V47(); virtual void V48(); virtual void V49();
    virtual void V50(); virtual void V51(); virtual void V52(); virtual void V53(); virtual void V54();
    virtual void V55(); virtual void V56(); virtual void V57(); virtual void V58();
    virtual Table* GetCatalogue();
};

extern "C" {
unsigned Menu_GetSelectedCatalogueRecord(void* self);
int ProcessAllowedResolvedHandles(void* state);
void* Menu_GetDisplayRecordRegistry(State* self);
void* MenuRecordList_LocateByKey(void** head, unsigned short value);
unsigned MenuRecord_GetType(void* self);
int FindLinkedNodeIndexByHalfword8(void** head, int value);
void Math_StoreSignedQuotientAndRemainder(void* obj, int numerator);
void MenuSelectionGrid_RefreshCursorAndSelectionCallback(void*, void*);
unsigned Menu_GetSelectedGridRow(void* self);
unsigned short Menu_GetSelectedGridColumn(const void* object);
unsigned short Menu_ReadGridEntryOrZero(Grid* self, unsigned row, unsigned column);
void* OV023_FindTypeSixFromTypeEight(unsigned unused, void* stateObject, void* candidate);
void Resource_SelectMatchingTypeEightLinkedRecord(unsigned short* self, void* context, int selected);
void Menu_PopulateCataloguePage(void*);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
// Original data: arm9/ov004 @ 0x021707c0; symbol: SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage.
extern unsigned char* SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2108760; symbol: Main_UnknownRoleZeroInitializedStorage.
extern unsigned char Main_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov004 @ 0x021549E4; symbol: func_ov004_021549e4; size: 0x198.
// Toggles catalogue rank order, pages the type-7 grid to the selected linked
// record, and restores the type-eight highlight.
extern "C" int Menu_ToggleCatalogueOrderPreservingSelection(void* self)
{
    char* selected = (char*)Menu_GetSelectedCatalogueRecord(self);
    if (!selected)
        return 0;

    SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage[0x7c] =
        (unsigned char)(SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage[0x7c] + 1);
    SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage[0x7c] =
        (unsigned char)(SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage[0x7c] & 1);
    ProcessAllowedResolvedHandles(self);

    void* tableRecord = MenuRecordList_LocateByKey(
        (void**)Menu_GetDisplayRecordRegistry((State*)self), 0x39);
    if (!tableRecord)
        return 0;
    Table* links = ((CatalogueRecord*)tableRecord)->GetCatalogue();
    if (!links)
        return 0;
    int index = FindLinkedNodeIndexByHalfword8((void**)links, *(short*)(selected + 0x18));
    if (index < 0)
        return 0;

    char* grid = (char*)MenuRecordList_LocateByKey(
        (void**)Menu_GetDisplayRecordRegistry((State*)self), 0x2c);
    if (!grid)
        return 0;
    if (MenuRecord_GetType(grid) != 7)
        return 0;

    int remainder = index % 16;
    short col = *(short*)(grid + 0x5e);
    *(short*)(grid + 0x5c) = (short)(index / 16);
    *(short*)(grid + 0x5e) = col;
    Math_StoreSignedQuotientAndRemainder(grid, (unsigned short)(short)remainder);
    MenuSelectionGrid_RefreshCursorAndSelectionCallback(grid, self);

    unsigned short key = Menu_ReadGridEntryOrZero(
        (Grid*)grid, Menu_GetSelectedGridRow(grid), Menu_GetSelectedGridColumn(grid));
    void* slot = MenuRecordList_LocateByKey(
        (void**)Menu_GetDisplayRecordRegistry((State*)self), key);
    if (slot && MenuRecord_GetType(slot) == 8) {
        void* canvas = OV023_FindTypeSixFromTypeEight((unsigned)grid, self, slot);
        if (canvas)
            Resource_SelectMatchingTypeEightLinkedRecord((unsigned short*)canvas, self, 0x8000);
    }

    Menu_PopulateCataloguePage(self);
    SoundSfx_StartCurrentSequenceArchiveEntry((char*)Main_UnknownRoleZeroInitializedStorage, 1, 0);
    return 0;
}
