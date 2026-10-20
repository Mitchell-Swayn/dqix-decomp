#include <globaldefs.h>
ARM
struct State;
struct Table;
// Virtual slot59 (+0xec) returns this record's catalogue table; earlier slots are unidentified.
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
struct RankLabels { unsigned short ids[2]; };
extern "C" {
extern char* SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage;
extern const RankLabels MenuRebuildCatalogueFilteredList_UnknownRoleInitializedBytes;
void Menu_GetCatalogueCategoryFilters(void*,short*,short*,short*);
void MotionRecord_SetSelectionParameterAndRefreshByKey(void* owner,unsigned short key,unsigned value,int refresh);
void* Menu_GetDisplayRecordRegistry(State* self);
void* MenuRecordList_LocateByKey(void** head,unsigned short value);
void Menu_ClearCatalogueSelection(Table* obj);
void Menu_BuildEnabledCatalogueByPrimaryRank(void** head,int a,int b,int c);
void Menu_BuildEnabledCatalogueBySecondaryRank(void** head,unsigned int a,unsigned int b,unsigned int c);
}
inline unsigned short GetRankLabel(int order) { RankLabels labels = MenuRebuildCatalogueFilteredList_UnknownRoleInitializedBytes; return labels.ids[order]; }
// Original: arm9/ov004 @ 0x0215482C; symbol: Menu_RebuildCatalogueFilteredList; size: 0x158.
// Updates category and sort labels, then rebuilds the catalogue in the selected rank order.
extern "C" int Menu_RebuildCatalogueFilteredList(State* self)
{
    short primary, secondary, subtype;
    short third, second, first;
    Menu_GetCatalogueCategoryFilters(self, &primary, &secondary, &subtype);
    unsigned short label = 0x2c;
    if (primary != 0) {
        if (subtype >= 0) label = subtype + 6;
        else if (secondary >= 0) {
            label = secondary + 0x11;
            if (secondary == 7) label = 0x18;
        }
    }
    MotionRecord_SetSelectionParameterAndRefreshByKey(self, 0x34, label, 15);
    MotionRecord_SetSelectionParameterAndRefreshByKey(self, 0x35, GetRankLabel((unsigned char)SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage[0x7c]), 15);
    int primaryOrder = (unsigned char)SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage[0x7c] == 0;
    CatalogueRecord* record = (CatalogueRecord*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self), 0x39);
    if (record) {
        Menu_GetCatalogueCategoryFilters(self, &first, &second, &third);
        Table* table = record->GetCatalogue();
        if (table) {
            Menu_ClearCatalogueSelection(table);
            if (primaryOrder) Menu_BuildEnabledCatalogueByPrimaryRank((void**)table, first, second, third);
            else Menu_BuildEnabledCatalogueBySecondaryRank((void**)table, first, second, third);
        }
    }
    return 0;
}
