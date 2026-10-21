#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off

struct State;
struct Node;
struct Grid {
    char padding[0x20];
    unsigned short* entries;
    unsigned short rows, columns;
};
struct PageCol {
    short page;
    short col;
};
struct ListView {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual void Pad55();
    virtual void Pad56();
    virtual void Pad57();
    virtual void Pad58();
    virtual Node** GetList();
};

extern "C" {
unsigned Menu_GetSelectedAlternateCatalogueRecord(void* self);
int World_ProcessEntriesUntilNegativeThreshold(void* object);
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
int Menu_PopulateAlternateCataloguePage(State* self);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
// Original data: arm9/ov004 @ 0x021707c4; symbol: MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage.
extern unsigned char* MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2108760; symbol: Main_UnknownRoleZeroInitializedStorage.
extern unsigned char Main_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov004 @ 0x02155BBC; symbol: func_ov004_02155bbc; size: 0x198.
// Toggles alternate-catalogue rank order, pages the type-7 grid to the selected
// linked record, and restores the type-eight highlight.
extern "C" int Menu_ToggleAlternateCatalogueOrderPreservingSelection(void* self)
{
    char* selected = (char*)Menu_GetSelectedAlternateCatalogueRecord(self);
    if (!selected)
        return 0;

    MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage[0x10] =
        (unsigned char)(MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage[0x10] + 1);
    MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage[0x10] =
        (unsigned char)(MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage[0x10] & 1);
    World_ProcessEntriesUntilNegativeThreshold(self);

    void* tableRecord = MenuRecordList_LocateByKey(
        (void**)Menu_GetDisplayRecordRegistry((State*)self), 0x39);
    if (!tableRecord)
        return 0;
    Node** links = ((ListView*)tableRecord)->GetList();
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

    Menu_PopulateAlternateCataloguePage((State*)self);
    SoundSfx_StartCurrentSequenceArchiveEntry((char*)Main_UnknownRoleZeroInitializedStorage, 1, 0);
    return 0;
}
