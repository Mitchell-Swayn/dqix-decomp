#include <globaldefs.h>
ARM
struct State;
extern "C" void *TileGrid_ResolveByKey(void *, unsigned);
extern "C" unsigned Menu_GetSelectedGridIndex(unsigned short *);
extern "C" void ProfileMenu_ClearSavedProfileRecord(void *);
extern "C" int ProfileMenu_PopulateSavedProfilePage(void *);
extern "C" int ProfileMenu_RestoreSavedListActions(void *);
extern "C" void Menu_QueueScriptEntry(State *, unsigned);
extern "C" void *memcpy(void *, const void *, unsigned);
struct SavedProfileRecord { unsigned char bytes[0x2c]; };
struct SavedProfileListHeader { unsigned char count; unsigned char unknown[3]; };
struct ProfileManagerView {
    unsigned char unknown[0x190];
    SavedProfileListHeader *list;
};
struct ProfileListGridView {
    unsigned char unknown[0x5c];
    short page;
    short pageCount;
};
// Original data: arm9/ov004 @ 0x02171030; symbol: data_ov004_02171030.
// Initially zero pointer; the profile list pointer is stored at manager offset 0x190.
extern "C" ProfileManagerView *MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage;
#pragma force_active on
// Original: arm9/ov004 @ 0x0216950C; symbol: func_ov004_0216950c; size: 0xF0.
// Removes the selected saved profile, shifts later records, and refreshes the list route.
extern "C" int ProfileMenu_RemoveSelectedSavedProfile(void *self)
{
    SavedProfileListHeader *list = MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->list;
    if (!list) return 0;
    ProfileListGridView *grid = (ProfileListGridView *)TileGrid_ResolveByKey(self, 100);
    int page = grid->page;
    SavedProfileRecord *record;
    SavedProfileRecord *next;
    int selected;
    selected = Menu_GetSelectedGridIndex((unsigned short *)grid) + page * 8;
    SavedProfileRecord *records = (SavedProfileRecord *)(list + 1);
    record = &records[selected];
    next = &records[selected + 1];
    ProfileMenu_ClearSavedProfileRecord(record);
    while (selected < list->count) {
        memcpy(record, next, sizeof(*record));
        ++record;
        ++next;
        ++selected;
    }
    ProfileMenu_ClearSavedProfileRecord(&((SavedProfileRecord *)(list + 1))[--list->count]);
    if (list->count <= 8) {
        grid->page = 0;
        grid->pageCount = 1;
    }
    ProfileMenu_PopulateSavedProfilePage(self);
    if (list->count == 0) {
        Menu_QueueScriptEntry((State *)self, 102);
        return 0;
    }
    ProfileMenu_RestoreSavedListActions(self);
    return 0;
}
