#include <globaldefs.h>
ARM
#pragma force_active on
// Retain the original entry when callers remain in weak-reference fallback objects.
extern "C" void Menu_GetAlternateCatalogueCategoryFilters(void*, short*, short*, short*);
extern "C" void MotionRecord_SetSelectionParameterAndRefreshByKey(void*, unsigned short, unsigned short, unsigned);
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
// Original data: arm9/ov004 @ 0x021707c4; symbol: data_ov004_021707c4.
// Zero-initialized mutable catalogue state pointer; byte +0x10 selects the rank order.
extern "C" unsigned char* MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov004 @ 0x0216fadc; symbol: data_ov004_0216fadc.
// Initialized rank-label identifiers indexed by the selected rank order.
extern "C" unsigned short MenuRebuildAlternateCatalogueFilteredList_UnknownRoleInitializedBytes[];
// Virtual slot59 (+0xec) returns this record's catalogue table; earlier slots are unidentified.
struct CatalogueTable;
struct CatalogueAlternateRecord {
    virtual void ReservedSlot0();
    virtual void ReservedSlot1();
    virtual void ReservedSlot2();
    virtual void ReservedSlot3();
    virtual void ReservedSlot4();
    virtual void ReservedSlot5();
    virtual void ReservedSlot6();
    virtual void ReservedSlot7();
    virtual void ReservedSlot8();
    virtual void ReservedSlot9();
    virtual void ReservedSlot10();
    virtual void ReservedSlot11();
    virtual void ReservedSlot12();
    virtual void ReservedSlot13();
    virtual void ReservedSlot14();
    virtual void ReservedSlot15();
    virtual void ReservedSlot16();
    virtual void ReservedSlot17();
    virtual void ReservedSlot18();
    virtual void ReservedSlot19();
    virtual void ReservedSlot20();
    virtual void ReservedSlot21();
    virtual void ReservedSlot22();
    virtual void ReservedSlot23();
    virtual void ReservedSlot24();
    virtual void ReservedSlot25();
    virtual void ReservedSlot26();
    virtual void ReservedSlot27();
    virtual void ReservedSlot28();
    virtual void ReservedSlot29();
    virtual void ReservedSlot30();
    virtual void ReservedSlot31();
    virtual void ReservedSlot32();
    virtual void ReservedSlot33();
    virtual void ReservedSlot34();
    virtual void ReservedSlot35();
    virtual void ReservedSlot36();
    virtual void ReservedSlot37();
    virtual void ReservedSlot38();
    virtual void ReservedSlot39();
    virtual void ReservedSlot40();
    virtual void ReservedSlot41();
    virtual void ReservedSlot42();
    virtual void ReservedSlot43();
    virtual void ReservedSlot44();
    virtual void ReservedSlot45();
    virtual void ReservedSlot46();
    virtual void ReservedSlot47();
    virtual void ReservedSlot48();
    virtual void ReservedSlot49();
    virtual void ReservedSlot50();
    virtual void ReservedSlot51();
    virtual void ReservedSlot52();
    virtual void ReservedSlot53();
    virtual void ReservedSlot54();
    virtual void ReservedSlot55();
    virtual void ReservedSlot56();
    virtual void ReservedSlot57();
    virtual void ReservedSlot58();
    virtual CatalogueTable* GetCatalogue();
};
static inline CatalogueTable* ReadCatalogueTable(void* record)
{
    return ((CatalogueAlternateRecord*)record)->GetCatalogue();
}
extern "C" void Menu_ClearCatalogueSelection(CatalogueTable*);
extern "C" void Menu_BuildAlternateCatalogueByPrimaryRank(void**, int, int, int, int);
extern "C" void Resource_BuildLinkedNodeChainWithExtraArgument(void**, unsigned, unsigned, unsigned, unsigned);
// Original: arm9/ov004 @ 0x02155a3c; symbol: func_ov004_02155a3c; size: 0x130.
// Updates category and sort labels, then rebuilds the alternate catalogue in the selected rank order.
extern "C" int Menu_RebuildAlternateCatalogueFilteredList(void* self)
{
    struct FilterScratch { short filters[3]; short subtype, secondary, primary; } scratch;
    Menu_GetAlternateCatalogueCategoryFilters(self, &scratch.primary, &scratch.secondary, &scratch.subtype);
    unsigned short label = 7;
    if (scratch.primary != 0 && scratch.secondary >= 0) {
        if (scratch.secondary == 8) label = 5;
        if (scratch.secondary == 9) label = 6;
    }
    MotionRecord_SetSelectionParameterAndRefreshByKey(self, 0x34, label, 15);
    MotionRecord_SetSelectionParameterAndRefreshByKey(self, 0x35,
        MenuRebuildAlternateCatalogueFilteredList_UnknownRoleInitializedBytes[(unsigned char)MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage[0x10]], 15);
    int primaryOrder = MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage[0x10] == 0;
    void* record = MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self), 0x39);
    if (record) {
        Menu_GetAlternateCatalogueCategoryFilters(self, &scratch.filters[0], &scratch.filters[1], &scratch.filters[2]);
        CatalogueTable* table = ReadCatalogueTable(record);
        if (table) {
            Menu_ClearCatalogueSelection(table);
            if (primaryOrder) Menu_BuildAlternateCatalogueByPrimaryRank((void**)table, scratch.filters[0], scratch.filters[1], scratch.filters[2], 1);
            else Resource_BuildLinkedNodeChainWithExtraArgument((void**)table, scratch.filters[0], scratch.filters[1], scratch.filters[2], 1);
        }
    }
    return 0;
}
