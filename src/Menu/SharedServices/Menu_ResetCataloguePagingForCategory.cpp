#include <globaldefs.h>
ARM
#pragma force_active on
// Retain this original entry while its callers remain in weak-reference fallback objects.
extern "C" void Menu_GetCatalogueCategoryFilters(void*, short*, short*, short*);
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void* GameState_AppendValueAndSetNodeFlags(void*, unsigned short, unsigned);
extern "C" void* GameState_ClearMaskFromKeyedEntry(void*, unsigned short, unsigned);
// The table accessor occupies virtual slot 59 (+0xec); preceding slots are unidentified.
struct CatalogueTable;
struct CataloguePagingRecord {
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
    return ((CataloguePagingRecord*)record)->GetCatalogue();
}
extern "C" short Menu_CountEnabledCatalogueEntriesByCategory(CatalogueTable*, int, int, int);
// Original: arm9/ov004 @ 0x021540a4; symbol: func_ov004_021540a4; size: 0x16c.
// Counts filtered entries, resets catalogue paging, and toggles empty-list widgets.
extern "C" int Menu_ResetCataloguePagingForCategory(void* self)
{
    short primary, secondary, subtype;
    Menu_GetCatalogueCategoryFilters(self, &primary, &secondary, &subtype);
    void* record = MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self), 0x39);
    if (!record) return 0;
    if (MenuRecord_GetType(record) != 0x12) return 0;
    CatalogueTable* table = ReadCatalogueTable(record);
    if (!record) return 0;
    int count = Menu_CountEnabledCatalogueEntriesByCategory(table, primary, secondary, subtype);
    short pageCount = (count + 15) / 16;
    if (!count) {
        GameState_AppendValueAndSetNodeFlags(self, 10, 8);
        GameState_ClearMaskFromKeyedEntry(self, 3, 4);
        unsigned short key = 0x1a;
        for (unsigned short i = 0; i < 16; ++key, ++i) {
            unsigned char* item = (unsigned char*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self), key);
            if (item) item[0xc] |= 8;
        }
        unsigned char* empty = (unsigned char*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self), 0x3a);
        if (empty) empty[0xc] &= ~8;
    } else {
        GameState_ClearMaskFromKeyedEntry(self, 10, 8);
        GameState_AppendValueAndSetNodeFlags(self, 0x3a, 8);
    }
    char* grid = (char*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self), 0x2c);
    if (!grid) return 0;
    if (MenuRecord_GetType(grid) != 7) return 0;
    *(short*)(grid + 0x5c) = 0;
    *(short*)(grid + 0x5e) = pageCount;
    return 0;
}
